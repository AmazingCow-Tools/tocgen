// std
#include <iostream>
#include <regex>
// Amazing Cow Libs
#include "CoreFS/CoreFS.h"
#include "CoreLog/CoreLog.h"
#include "CoreFile/CoreFile.h"
#include "CoreString/CoreString.h"

//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
#define COW_TOCGEN_VERSION_MAJOR    "0"
#define COW_TOCGEN_VERSION_MINOR    "1"
#define COW_TOCGEN_VERSION_REVISION "0"

#define COW_TOCGEN_VERSION           \
        COW_TOCGEN_VERSION_MAJOR "." \
        COW_TOCGEN_VERSION_MINOR "." \
        COW_TOCGEN_VERSION_REVISION

#define PROGRAM_NAME    "tocgen"
#define COPYRIGHT_YEARS "2018"


//----------------------------------------------------------------------------//
// Help / Version                                                             //
//----------------------------------------------------------------------------//
void show_help(int errorCode) noexcept
{
    std::string str = R"(Usage:
  %s [-h] [-v] [-V] <filename>

Options:
  *-h --help    : Show this screen.
  *-v --version : Show app version and copyright.

   -V --verbose : Turn debug logs on.

   <filename> : The file's name that will be parsed.

Notes:
  Options marked with * are exclusive, i.e. the gosh will run that
  and exit after the operation.

)";

    printf(CoreString::Format(str, PROGRAM_NAME).c_str());
    exit(errorCode);
}

void show_version() noexcept
{
    std::string str = R"(%s - %s - N2OMatt <n2omatt@amazingcow.com>
Copyright (c) %s - Amazing Cow
This is a free software (GPLv3) - Share/Hack it
Check http://www.amazingcow.com for more :)
)";

    printf(CoreString::Format(
        str,
        PROGRAM_NAME,
        COW_TOCGEN_VERSION,
        COPYRIGHT_YEARS
    ).c_str());

    exit(0);
}

std::string comment_string() noexcept
{
    std::string str = R"(
    %s v%s - Amazing Cow - GPLv3
    n2omatt <n2omatt@amazingcow.com>
    http://amazingcow.com
)";

    return CoreString::Format(str, PROGRAM_NAME, COW_TOCGEN_VERSION);
}

//----------------------------------------------------------------------------//
// Data Structures                                                            //
//----------------------------------------------------------------------------//
struct Node
{
    int         value    = 0;
    std::string contents = "";

    Node *pParent = nullptr;
    std::vector<Node> children;

    Node() = default;

    Node(int value_, const std::string &contents_, Node *pParent_) :
        value   (   value_),
        contents(contents_),
        pParent ( pParent_)
    {
        // Empty...
    }
};

void print_tree_html(const Node &node, int level = 0) noexcept
{
    auto spaces = std::string(level * 2, ' ');
    if(node.value == 0)
    {
        printf("<!-- %s --> \n", comment_string().c_str());
        printf("<b>Table of Contents:</b>\n");
    }
    else
    {
        printf(
           "%s<li>%s</li> <!-- <h%d> -->\n",
            spaces.c_str(),
            node.contents.c_str(),
            node.value
        );
    }
    if(!node.children.empty())
    {
        printf("%s<ul>\n", spaces.c_str());
        for(const auto &child : node.children)
            print_tree_html(child, level + 1);
        printf("%s</ul>\n", spaces.c_str());
    }
}


//----------------------------------------------------------------------------//
// Entry Point                                                                //
//----------------------------------------------------------------------------//
int main(int argc, char *argv[])
{
    if(argc < 2)
        show_help(1);

    auto filename = std::string();
    auto verbose  = false;

    //--------------------------------------------------------------------------
    // Parse the command line options.
    // COWTODO(n2omatt): Would be nicer to user CMD later...
    for(int i = 1; i < argc; ++i)
    {
        // Help.
        if(CoreString::StartsWith(argv[i], "--help") ||
           CoreString::StartsWith(argv[i], "-h"))
        {
            show_help(0);
        }
        // Version.
        else if(CoreString::StartsWith(argv[i], "--version") ||
                CoreString::StartsWith(argv[i], "-v"))
        {
            show_version();
        }
        // Verbose.
        else if(CoreString::StartsWith(argv[i], "--verbose") ||
                CoreString::StartsWith(argv[i], "-V"))
        {
            verbose = true;
        }
        // Filename.
        else
        {
            filename = argv[i];
        }
    }

    // Sanity Checks...
    if(filename.empty())
        show_help(1);

    if(!CoreFS::IsFile(filename))
        CoreLog::Fatal("Invalid filename: (%s)", filename);

    // Configure Logger...
    CoreLog::GetDefaultLogger().SetLevel(
        (verbose)
            ? CoreLog::Logger::LOG_LEVEL_VERBOSE
            : CoreLog::Logger::LOG_LEVEL_NONE
    );

    //--------------------------------------------------------------------------
    // Create the regexes...
    auto regex_tag_h = std::regex("<h[1-6]>.*<\\/h[1-6]>");
    std::smatch sm;

    //--------------------------------------------------------------------------
    // Head is the main node of the TOC tree
    // p_currNode is the current node that we're working on.
    auto head       = Node{};
    auto p_currNode = &head;

    //--------------------------------------------------------------------------
    // Parse the file lines.
    auto lines = CoreFile::ReadAllLines(filename);
    auto lineno = 0; // Just to let us have a clue of where the string is.
    for(const auto &line : lines)
    {
        ++lineno;
        if(CoreString::IsNullOrWhiteSpace(line))
            continue;

        // Check if we're on <H*> line.
        auto clean_line = CoreString::Trim(line, " \n");
        if(!std::regex_search(line, sm, regex_tag_h))
            continue;

        // Get the line's info.
        auto value    = int(clean_line[2]) - int('1') + 1;
        auto contents = CoreString::Trim(clean_line.substr(4, clean_line.size() -9));

        // Log... ;D
        CoreLog::Debug("(%d) %s", lineno, clean_line);
        CoreLog::Debug("[Curr] Value: %d - Contents: %s", p_currNode->value, p_currNode->contents);
        CoreLog::Debug("[New ] Value: %d - Contents: %s", value, contents);

        //----------------------------------------------------------------------
        // Adding children to current node.
        if(p_currNode->value < value)
        {
            auto node = Node(value, contents, p_currNode);

            p_currNode->children.push_back(node);
            p_currNode = &p_currNode->children.back();
        }
        //----------------------------------------------------------------------
        // Adding siblings to current node.
        else if(p_currNode->value == value)
        {
            p_currNode = p_currNode->pParent;
            auto node = Node(value, contents, p_currNode);

            p_currNode->children.push_back(node);
            p_currNode = &p_currNode->children.back();
        }
        //----------------------------------------------------------------------
        // Adding siblings to the parent node.
        else if(p_currNode->value > value)
        {
            while(p_currNode->value >= value)
                p_currNode = p_currNode->pParent;

            auto node = Node(value, contents, p_currNode);

            p_currNode->children.push_back(node);
            p_currNode = &p_currNode->children.back();
        }
    }

    print_tree_html(head);
    return 0;
}
