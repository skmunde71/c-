# Unix Command Cheat Sheet 🚀

## File System Navigation

| Command | Description | Example |
|---------|-------------|---------|
| `pwd` | Print working directory | `pwd` |
| `ls` | List files | `ls -la` |
| `cd` | Change directory | `cd /path/to/dir` |
| `mkdir` | Create directory | `mkdir -p dir1/dir2` |
| `rmdir` | Remove empty directory | `rmdir dirname` |

## File Operations

| Command | Description | Example |
|---------|-------------|---------|
| `cp` | Copy files | `cp -r source dest` |
| `mv` | Move/rename files | `mv oldname newname` |
| `rm` | Remove files | `rm -rf directory` |
| `touch` | Create empty file | `touch filename` |
| `ln` | Create links | `ln -s target linkname` |

## File Viewing

| Command | Description | Example |
|---------|-------------|---------|
| `cat` | Display file content | `cat filename` |
| `less` | Page through file | `less filename` |
| `head` | Show first lines | `head -n 10 filename` |
| `tail` | Show last lines | `tail -f filename` |
| `more` | Page through file | `more filename` |

## File Permissions

| Command | Description | Example |
|---------|-------------|---------|
| `chmod` | Change permissions | `chmod 755 filename` |
| `chown` | Change ownership | `chown user:group file` |
| `chgrp` | Change group | `chgrp groupname file` |
| `umask` | Set default permissions | `umask 022` |

### Permission Numbers
- `4` = Read (r)
- `2` = Write (w)  
- `1` = Execute (x)
- `7` = Read + Write + Execute (4+2+1)
- `6` = Read + Write (4+2)
- `5` = Read + Execute (4+1)

## Text Processing

| Command | Description | Example |
|---------|-------------|---------|
| `grep` | Search text | `grep "pattern" file` |
| `sed` | Stream editor | `sed 's/old/new/g' file` |
| `awk` | Text processor | `awk '{print $1}' file` |
| `sort` | Sort lines | `sort -n file` |
| `uniq` | Remove duplicates | `uniq file` |
| `cut` | Cut fields | `cut -d: -f1 file` |
| `paste` | Merge files | `paste file1 file2` |
| `wc` | Word count | `wc -l file` |

## Process Management

| Command | Description | Example |
|---------|-------------|---------|
| `ps` | Process status | `ps aux` |
| `top` | Interactive process viewer | `top` |
| `htop` | Enhanced top | `htop` |
| `kill` | Terminate process | `kill -9 PID` |
| `killall` | Kill by name | `killall processname` |
| `pkill` | Kill by pattern | `pkill -f pattern` |
| `jobs` | List background jobs | `jobs` |
| `bg` | Resume background job | `bg %1` |
| `fg` | Bring job to foreground | `fg %1` |

## System Information

| Command | Description | Example |
|---------|-------------|---------|
| `uname` | System information | `uname -a` |
| `whoami` | Current user | `whoami` |
| `id` | User/group info | `id` |
| `who` | Logged in users | `who` |
| `w` | Detailed user info | `w` |
| `uptime` | System uptime | `uptime` |
| `date` | Current date/time | `date` |

## System Resources

| Command | Description | Example |
|---------|-------------|---------|
| `free` | Memory usage | `free -h` |
| `df` | Disk usage | `df -h` |
| `du` | Directory size | `du -h directory` |
| `iostat` | I/O statistics | `iostat 1 5` |
| `vmstat` | Virtual memory | `vmstat 1 5` |
| `lscpu` | CPU information | `lscpu` |
| `lsblk` | Block devices | `lsblk` |

## Networking

| Command | Description | Example |
|---------|-------------|---------|
| `ip` | IP configuration | `ip addr show` |
| `ifconfig` | Network interfaces | `ifconfig` |
| `netstat` | Network statistics | `netstat -tuln` |
| `ss` | Socket statistics | `ss -tuln` |
| `ping` | Test connectivity | `ping -c 3 host` |
| `traceroute` | Trace route | `traceroute host` |
| `nslookup` | DNS lookup | `nslookup host` |
| `dig` | DNS lookup | `dig host` |
| `curl` | HTTP client | `curl -I url` |
| `wget` | Download file | `wget url` |

## SSH & Remote Access

| Command | Description | Example |
|---------|-------------|---------|
| `ssh` | Secure shell | `ssh user@host` |
| `scp` | Secure copy | `scp file user@host:path` |
| `rsync` | Remote sync | `rsync -av source dest` |
| `ssh-keygen` | Generate SSH key | `ssh-keygen -t rsa` |
| `ssh-copy-id` | Copy key to host | `ssh-copy-id user@host` |

## Package Management

### Debian/Ubuntu
| Command | Description | Example |
|---------|-------------|---------|
| `apt update` | Update package list | `apt update` |
| `apt upgrade` | Upgrade packages | `apt upgrade` |
| `apt install` | Install package | `apt install package` |
| `apt remove` | Remove package | `apt remove package` |
| `apt search` | Search packages | `apt search package` |

### Red Hat/CentOS
| Command | Description | Example |
|---------|-------------|---------|
| `yum update` | Update packages | `yum update` |
| `yum install` | Install package | `yum install package` |
| `yum remove` | Remove package | `yum remove package` |
| `yum search` | Search packages | `yum search package` |

## Service Management

| Command | Description | Example |
|---------|-------------|---------|
| `systemctl start` | Start service | `systemctl start service` |
| `systemctl stop` | Stop service | `systemctl stop service` |
| `systemctl restart` | Restart service | `systemctl restart service` |
| `systemctl status` | Service status | `systemctl status service` |
| `systemctl enable` | Enable at boot | `systemctl enable service` |
| `systemctl disable` | Disable at boot | `systemctl disable service` |

## File Finding & Searching

| Command | Description | Example |
|---------|-------------|---------|
| `find` | Find files | `find . -name "*.txt"` |
| `locate` | Find files by name | `locate filename` |
| `which` | Find command path | `which command` |
| `whereis` | Find command files | `whereis command` |
| `type` | Command type | `type command` |

## Compression & Archives

| Command | Description | Example |
|---------|-------------|---------|
| `tar` | Archive files | `tar -czf archive.tar.gz dir` |
| `gzip` | Compress files | `gzip filename` |
| `gunzip` | Decompress files | `gunzip filename.gz` |
| `zip` | Create zip archive | `zip archive.zip files` |
| `unzip` | Extract zip | `unzip archive.zip` |

## User Management

| Command | Description | Example |
|---------|-------------|---------|
| `useradd` | Add user | `useradd username` |
| `userdel` | Delete user | `userdel username` |
| `passwd` | Set password | `passwd username` |
| `usermod` | Modify user | `usermod -aG group user` |
| `groupadd` | Add group | `groupadd groupname` |
| `groups` | Show user groups | `groups username` |

## Logs & Monitoring

| Command | Description | Example |
|---------|-------------|---------|
| `journalctl` | Systemd journal | `journalctl -f` |
| `tail` | Follow log file | `tail -f /var/log/syslog` |
| `logrotate` | Rotate logs | `logrotate -f config` |
| `dmesg` | Kernel messages | `dmesg | tail -20` |

## Shell Scripting

| Command | Description | Example |
|---------|-------------|---------|
| `#!/bin/bash` | Shebang | `#!/bin/bash` |
| `$0` | Script name | `echo $0` |
| `$1, $2...` | Arguments | `echo $1` |
| `$@` | All arguments | `echo $@` |
| `$#` | Argument count | `echo $#` |
| `$?` | Exit status | `echo $?` |

## Environment Variables

| Variable | Description | Example |
|----------|-------------|---------|
| `$HOME` | Home directory | `echo $HOME` |
| `$PATH` | Executable path | `echo $PATH` |
| `$USER` | Current user | `echo $USER` |
| `$PWD` | Current directory | `echo $PWD` |
| `$SHELL` | Current shell | `echo $SHELL` |

## Redirection & Pipes

| Symbol | Description | Example |
|--------|-------------|---------|
| `>` | Output redirection | `echo "text" > file` |
| `>>` | Append output | `echo "text" >> file` |
| `<` | Input redirection | `cat < file` |
| `|` | Pipe | `ls | grep pattern` |
| `2>` | Error redirection | `command 2> error.log` |
| `&>` | All output redirection | `command &> output.log` |

## Common Options

### ls Options
- `-a` : Show hidden files
- `-l` : Long format
- `-h` : Human readable sizes
- `-R` : Recursive listing
- `-t` : Sort by time

### find Options
- `-name` : Search by name
- `-type` : Search by type (f=file, d=directory)
- `-size` : Search by size
- `-mtime` : Search by modification time
- `-exec` : Execute command on results

### grep Options
- `-i` : Case insensitive
- `-r` : Recursive search
- `-v` : Invert match
- `-n` : Show line numbers
- `-l` : Show only filenames

### ps Options
- `a` : All processes
- `u` : User-oriented format
- `x` : Include processes without terminal
- `-e` : All processes
- `-f` : Full format

## Quick Tips

1. **Tab completion**: Press Tab to complete commands and filenames
2. **History**: Use `history` to see command history, `!n` to repeat command n
3. **Aliases**: Create shortcuts with `alias name='command'`
4. **Functions**: Define functions in your shell profile
5. **Man pages**: Use `man command` for detailed help
6. **Info pages**: Use `info command` for comprehensive documentation
7. **Help**: Use `command --help` for quick help

## Keyboard Shortcuts

| Shortcut | Description |
|----------|-------------|
| `Ctrl+C` | Cancel current command |
| `Ctrl+D` | End of input (EOF) |
| `Ctrl+L` | Clear screen |
| `Ctrl+R` | Search command history |
| `Ctrl+Z` | Suspend process |
| `Ctrl+A` | Move to beginning of line |
| `Ctrl+E` | Move to end of line |
| `Ctrl+U` | Clear line before cursor |
| `Ctrl+K` | Clear line after cursor |
| `Ctrl+W` | Delete word before cursor |

## File Extensions

| Extension | Type | Example |
|-----------|------|---------|
| `.sh` | Shell script | `script.sh` |
| `.txt` | Text file | `document.txt` |
| `.log` | Log file | `application.log` |
| `.conf` | Configuration | `config.conf` |
| `.tar.gz` | Compressed archive | `backup.tar.gz` |
| `.deb` | Debian package | `package.deb` |
| `.rpm` | Red Hat package | `package.rpm` |

Remember: This cheat sheet covers the most common commands. Use `man command` for detailed information about any specific command!