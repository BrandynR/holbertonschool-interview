# 0x10. Rain
 Specializations - Interview Preparation ― Algorithms

 by Jesse Hedden, Software Engineer at Holberton School

 Ongoing project - started 08-20-2020, must end by 08-27-2020 (in about 7 hours) - you're done with 0% of tasks.

 Checker was released at 08-23-2020 12:00 PM

 QA review fully automated.

 linear time python

Requirements
General
Allowed editors: vi, vim, emacs
All your files will be interpreted/compiled on Ubuntu 14.04 LTS using python3 (version 3.4.3)
All your files should end with a new line
The first line of all your files should be exactly #!/usr/bin/python3
A README.md file, at the root of the folder of the project, is mandatory
Your code should use the PEP 8 style (version 1.7.x)
You are not allowed to import any module
All modules and functions must be documented
All your files must be executable
Tasks

0. Rain mandatory
Given a list of non-negative integers representing walls of width 1, calculate how much water will be retained after it rains.

Prototype: def rain(walls)
walls is a list of non-negative integers.
Return: Integer indicating total amount of rainwater retained.
Assume that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water.
If the list is empty return 0.
jesse@ubuntu:~/0x10$ cat 0_main.py
#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))

jesse@ubuntu:~/0x10$ 
jesse@ubuntu:~/0x10$ ./0_main.py
6
jesse@ubuntu:~/0x10$ 
Repo:

GitHub repository: holbertonschool-interview
Directory: 0x10-rain
File: 0-rain.py
