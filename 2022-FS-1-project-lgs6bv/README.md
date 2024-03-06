# README
Please make a note of which project option you have chosen in this `README.md` file.

For each option, you must enter answers to questions in this `README.md` file,
as well as add any configuration files or scripts you wrote for the assignment to this repository. 

#### Good Luck

Option B)

2) Command substitution allows the output of a command to be substituted in place of the command itself.

Ex. 1)
#!/bin/bash
echo Today is $(date)

Ex. 2)
#!/bin/bash
current_directory=$(pwd)
echo "The current directory is $current_directory"

3)

a) When you log out SIGHUP is sent to all jobs if they are running or stopped. SIGHUP is the signal that informs when the terminal has been disconnected and stops all jobs. 

b) The disown command removes the job from the job list. 

c) The wait command is used to wait for the running background proccesses to finish before returning the exit status.

Ex. c)
#!/bin/bash
sleep 5 &
PID=$!
sleep 15 &
wait $PID
echo "The first command ran for 5 seconds and exited with status $?"
wait $!
echo "The second command ran for 10 seconds and exited with status $?"

4)
cal - Display a calendar for a specific month or year
$cal [-smjy13] [[[day] month] year] 

history - Display a list of previously entered commands
$history

ping - Send an ICMP echo request to a remote host
$ping [destination_host]

nslookup - Query DNS name servers for information about a domain or IP address
$nslookup [server]

free - Display information about free and used system memory
$free

whoami - Display the current user's username
$whoami

uptime - Display the system uptime and load averages
$uptime

chmod - Change the permissions of a file or directory
$chmod [Options] [Mode] file

who - Print all usernames currently logged in
$who

alias - Create an alias for a command
$alias [-p] [name[=value]]