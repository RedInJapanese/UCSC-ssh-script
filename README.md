# UCSC ssh script 🍌🐌
  A C script that automates ssh login into the UCSC timeshare.

## Running
  This repository contains three different executable files for either Windows, Mac, or Linux. Each version is specified in its name.
  Run the following in order to see the help message from the login binary:

  - Windows: `./win_login -h`
  - Mac: `./mac_login -h`
  - Linux: `./lin_login -h`

  Run the following in order to login to your timeshare server:
  ```
  ./(insert os name here)_login -u <your cruz id here(only your cruz id, no @ afterwards)>
  ```
  
  ### Note
  If you are interested in making the executable yourself, go into the directory called 'src' and run `make`. The compiler used can be changed in the flags of the makefile itself. 
  
  ### Note
  If you wish to compile the binary without the ascii art, go into the directory called 'src', comment out the function call(`printArt("slugart.txt", art);`), and   run
  `make` afterwards. This will allow you to move the binary into different directories without the ascii art text file.  
## Using the -t command
```
./(insert o name here)_login -u <your cruz id here(only your cruz id, no @ afterwards)> -t <valid ascii art text file>
```
![Imgur](https://imgur.com/eDhuFj7.gif)
## Example
  ```
  ./win_login -u abasu2
  ```
![Imgur](https://i.imgur.com/0x3cmC9.gif)
