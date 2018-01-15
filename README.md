# tocgen

**Made with <3 by [Amazing Cow](http://www.amazingcow.com).**


<!-- ####################################################################### -->
<!-- Websites ############################################################## -->
<!-- ####################################################################### -->

## Websites:

* [AmazingCow page](http://www.amazingcow.com).


<!-- ####################################################################### -->
<!-- Description ########################################################### -->
<!-- ####################################################################### -->

## Description:

A stupidly simple _HTML Table of Contents_ generator.


### Motivation:

We want _ToC_ on our pages, that's it ;D

<br>

As usual, you are **very welcomed** to **share** and **hack** it.


<!-- ####################################################################### -->
<!-- Usage ################################################################# -->
<!-- ####################################################################### -->

## Usage:
```
  tocgen [-h] [-v] [-V] <filename>

Options:
  *-h --help    : Show this screen.
  *-v --version : Show app version and copyright.

   -V --verbose : Turn debug logs on.

   <filename> : The file's name that will be parsed.

Notes:
  Options marked with * are exclusive, i.e. the gosh will run that
  and exit after the operation.
```


<!-- ####################################################################### -->
<!-- Examples ############################################################## -->
<!-- ####################################################################### -->

## Examples:

```bash
tocgen /path/to/the/html/page.html # Will output to the console.
```


<!-- ####################################################################### -->
<!-- Documentation ######################################################### -->
<!-- ####################################################################### -->

## Documentation:

<!-- 
    There's no docs yet...

We strive to make our source code fully documented.   
While there are a myriad of comments, one might find useful take a look at:

* [Doxygen Docs](http://www.amazingcow.com/docs/tocgen/). 
-->

Anyway if you didn't understand something let us know sending a mail to  
[help_floss@amazingcow.com]() with the subject filled with the
name of this repo.


<!-- ####################################################################### -->
<!-- Dependencies ########################################################## -->
<!-- ####################################################################### -->

## Dependencies:

* [CoreAssert](https://github.com/AmazingCow-Libs/CoreAssert)
* [CoreFile](https://github.com/AmazingCow-Libs/CoreFile)
* [CoreFS](https://github.com/AmazingCow-Libs/CoreFS)
* [CoreLog](https://github.com/AmazingCow-Libs/CoreLog)
* [CoreString](https://github.com/AmazingCow-Libs/CoreString)
* [libtermcolor](https://github.com/AmazingCow-Libs/libtermcolor)

All dependecies are ```git submodules``` so issue:
```bash
git submodule update --init --recursive
```
and you're good to go!


<!-- ####################################################################### -->
<!-- License ############################################################### -->
<!-- ####################################################################### -->

## License:

This software is **proudly** released under [GPLv3](https://www.gnu.org/licenses/gpl-3.0.en.html).



<!-- ####################################################################### -->
<!-- BUGS ################################################################## -->
<!-- ####################################################################### -->

## BUGS:

We strive to make all our code the most bug-free as possible - But we know 
that few of them can pass without we notice ;).

Please if you find any bug report to [bugs_floss@amazingcow.com]() 
with the name of this project and/or create an issue here in Github.



<!-- ####################################################################### -->
<!-- TODO ################################################################## -->
<!-- ####################################################################### -->

## TODO:

Check the TODO file for general things.

This projects uses the COWTODO tags.   
So install [cowtodo](http://www.github.com/AmazingCow-Tools/COWTODO) and run:

``` bash
$ cd path/to/the/project
$ cowtodo 
```

That's gonna give you all things to do :D.



<!-- ####################################################################### -->
<!-- Others ################################################################ -->
<!-- ####################################################################### -->

## Others:

Check our other Free Software repos and take a look at our 
[free software site](http://floss.amazingcow.com).
