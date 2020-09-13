1. No bug.

2.group member name: Shu Pan, Jia Zeng, Lin li.
Jia Zeng and Lin Li mainly implemented Step1 to Step 4.
Shu Pan mainly implemented Step5 to Step 7.

3.
ls command

Situation:root has a directory called dir. In the root/dir, there are two files: image.img; file.txt. They 
are both empty.

H:\504C++\lab5-hulukids_lab5\lab5\Debug>lab5.exe
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
dir

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls -l
dir     directory        size: 19
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ls -l
image.img       image    size: 0
file.txt        text     size: 0
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $

4.
rm command

Situation1:root has a directory called dir. In the root/dir, there are two files: image.img; file.txt. They 
are both empty. The file.txt is open.

H:\504C++\lab5-hulukids_lab5\lab5\Debug>lab5.exe
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm dir
The directory is non-empty, you cannot remove it.
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ls
image.img
file.txt

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ cd ..
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm dir -r
file.txt is currently in use
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ls
file.txt

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ls dir
file.txt

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $


Situation2:root has a directory called dir. In the root/dir, there are two files: image.img; file.txt. They 
are both empty and closed.

H:\504C++\lab5-hulukids_lab5\lab5\Debug>lab5.exe
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm dir -r
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ls

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $

5
cat command
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch file.txt
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat file.txt
root/file.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
12345
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds file.txt
12345

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat file.txt -a
txt -a
root/file.txt
12345

Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
6789
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds file.txt
12345
6789

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat file.txt
root/file.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
oops, I forgot to save
:q
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds file.txt
12345
6789

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat file.txt
root/file.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
overwrite
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds file.txt
overwrite

6.
ds command

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch image.img
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat image.img
root/image.img
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
X X X X X3
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds image.img
X X
 X
X X

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds image.img -d
fpath : root/image.img
X X X X X
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $

7.
cp command

Situation: I created a image.img at root/ and copied it to root/dir1. I modify the copied one, and the original 
oene didn't change.

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch image.img
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat image.img
root/image.img
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
X X X X X3
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cp image.img root/dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ls
image.img

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ds image.img
X X
 X
X X

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ cat image.img
root/dir1/image.img
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
X  X2
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ds image.img
X
 X

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ cd ..
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds image.img
X X
 X
X X

8.
sym command

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch image.img
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat image.img
root/image.img
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
X X X X X3
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ sym image.img root/dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ls
image.img

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ds image.img
X X
 X
X X

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ cat image.img
root/dir1/image.img
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
X  X2
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ cd ..
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds image.img
X
 X

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm image.img
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
dir
dir1

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ls
image.img
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ds image.img
X
 X