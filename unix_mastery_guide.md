# Unix Mastery Guide 🐧

## Table of Contents
1. [Unix Philosophy](#unix-philosophy)
2. [File System Navigation](#file-system-navigation)
3. [File Operations](#file-operations)
4. [Text Processing](#text-processing)
5. [Process Management](#process-management)
6. [User Management](#user-management)
7. [Networking](#networking)
8. [Shell Scripting](#shell-scripting)
9. [System Administration](#system-administration)
10. [Advanced Tools](#advanced-tools)

## Unix Philosophy

The Unix philosophy is built on several core principles:

- **Do one thing and do it well**: Each program should have a single, well-defined purpose
- **Text streams**: Programs communicate through text streams
- **Composition**: Programs can be combined to create more complex functionality
- **Portability**: Write programs that work on any Unix-like system
- **Simplicity**: Keep things simple and avoid unnecessary complexity

## File System Navigation

### Essential Commands

```bash
# Current directory
pwd

# List files and directories
ls -la

# Change directory
cd /path/to/directory
cd ..          # Go up one level
cd ~           # Go to home directory
cd -           # Go to previous directory

# Create directories
mkdir directory_name
mkdir -p parent/child/grandchild  # Create nested directories

# Remove directories
rmdir directory_name               # Remove empty directory
rm -rf directory_name             # Remove directory and contents (dangerous!)
```

### File System Structure

```
/                   # Root directory
├── bin/           # Essential system binaries
├── boot/          # Boot loader files
├── dev/           # Device files
├── etc/           # System configuration files
├── home/          # User home directories
├── lib/           # System libraries
├── media/         # Mount points for removable media
├── mnt/           # Mount points for temporary mounts
├── opt/           # Optional application software
├── proc/          # Process information
├── root/          # Root user home directory
├── run/           # Runtime variable data
├── sbin/          # System binaries
├── srv/           # Service data
├── sys/           # System information
├── tmp/           # Temporary files
├── usr/           # User utilities and applications
└── var/           # Variable data
```

## File Operations

### File Management

```bash
# Copy files
cp source_file destination_file
cp -r source_dir destination_dir

# Move/rename files
mv old_name new_name
mv file1 file2 destination_dir

# Remove files
rm filename
rm -i filename     # Interactive removal
rm -f filename     # Force removal without prompts

# View file contents
cat filename       # Display entire file
less filename      # Page through file
head -n 10 filename # Show first 10 lines
tail -n 10 filename # Show last 10 lines
tail -f filename   # Follow file in real-time

# File permissions
chmod 755 filename # Change permissions
chmod +x filename  # Make executable
chown user:group filename # Change ownership
```

### File Permissions

Permissions are represented as three groups of three characters:
- **Owner** (first group): rwx (read, write, execute)
- **Group** (second group): rwx (read, write, execute)
- **Others** (third group): rwx (read, write, execute)

```bash
# Permission examples
-rw-r--r--  # File: owner can read/write, group and others can read
drwxr-xr-x  # Directory: owner can read/write/execute, group and others can read/execute
-rwxr-xr-x  # Executable file: owner can read/write/execute, group and others can read/execute

# Numeric permissions
chmod 644 filename  # rw-r--r--
chmod 755 filename  # rwxr-xr-x
chmod 600 filename  # rw-------
```

## Text Processing

### Essential Text Tools

```bash
# Search in files
grep "pattern" filename
grep -i "pattern" filename    # Case-insensitive
grep -r "pattern" directory   # Recursive search
grep -v "pattern" filename    # Exclude lines matching pattern

# Stream editor
sed 's/old/new/g' filename    # Replace text
sed -i 's/old/new/g' filename # Edit file in place

# Text processing
awk '{print $1}' filename     # Print first field
awk -F: '{print $1}' filename # Use colon as field separator

# Sort and unique
sort filename                  # Sort lines
sort -n filename              # Numeric sort
sort -u filename              # Remove duplicates
uniq filename                 # Remove consecutive duplicates

# Cut and paste
cut -d: -f1 filename          # Cut first field using colon delimiter
paste file1 file2             # Merge files line by line
```

### Advanced Text Processing

```bash
# Find and replace across multiple files
find . -name "*.txt" -exec sed -i 's/old/new/g' {} \;

# Count lines, words, characters
wc filename
wc -l filename    # Lines only
wc -w filename    # Words only
wc -c filename    # Characters only

# Compare files
diff file1 file2
diff -u file1 file2    # Unified diff format
```

## Process Management

### Process Commands

```bash
# View processes
ps aux                    # All processes
ps -ef                    # Alternative format
top                       # Interactive process viewer
htop                      # Enhanced top (if available)

# Process control
kill PID                  # Terminate process
kill -9 PID              # Force kill
killall process_name     # Kill all processes by name
pkill process_name       # Kill processes by name

# Background processes
command &                 # Run in background
nohup command &          # Run in background, survive logout
bg                        # Resume background job
fg                        # Bring background job to foreground
jobs                      # List background jobs
```

### System Monitoring

```bash
# System resources
free -h                   # Memory usage
df -h                     # Disk usage
du -h directory           # Directory size
iostat                    # I/O statistics
vmstat                    # Virtual memory statistics

# System information
uname -a                  # System information
cat /etc/os-release       # OS version
lscpu                     # CPU information
lsblk                     # Block device information
```

## User Management

### User Commands

```bash
# User information
whoami                    # Current user
who                       # Logged in users
w                         # Detailed user information
id                        # User and group IDs

# User management (requires root)
useradd username          # Add user
userdel username          # Delete user
passwd username           # Set password
usermod -aG group username # Add user to group

# Group management
groups username           # Show user groups
groupadd groupname        # Create group
groupdel groupname        # Delete group
```

### Sudo and Permissions

```bash
# Execute command as root
sudo command
sudo -i                   # Interactive root shell
sudo su -                 # Switch to root user

# Edit sudoers file safely
sudo visudo

# Check sudo privileges
sudo -l
```

## Networking

### Network Commands

```bash
# Network configuration
ip addr                   # Show IP addresses
ip route                  # Show routing table
ifconfig                  # Network interface configuration (deprecated)
netstat -tuln            # Show listening ports
ss -tuln                 # Modern alternative to netstat

# Network connectivity
ping hostname             # Test connectivity
traceroute hostname       # Trace route to host
nslookup hostname         # DNS lookup
dig hostname              # Advanced DNS lookup

# Network services
telnet hostname port      # Test port connectivity
nc -zv hostname port      # Netcat port scan
curl -I http://hostname   # HTTP request
wget http://hostname      # Download file
```

### SSH and Remote Access

```bash
# SSH connection
ssh username@hostname
ssh -p port username@hostname
ssh -i keyfile username@hostname

# SCP file transfer
scp localfile username@hostname:/remote/path
scp username@hostname:/remote/file localpath

# SSH key management
ssh-keygen -t rsa -b 4096
ssh-copy-id username@hostname
```

## Shell Scripting

### Basic Scripting

```bash
#!/bin/bash
# This is a comment

# Variables
name="World"
echo "Hello, $name!"

# Command substitution
current_date=$(date)
echo "Current date: $current_date"

# Conditional statements
if [ -f "file.txt" ]; then
    echo "File exists"
else
    echo "File does not exist"
fi

# Loops
for i in {1..5}; do
    echo "Number: $i"
done

while [ $i -lt 10 ]; do
    echo "Count: $i"
    ((i++))
done
```

### Advanced Scripting

```bash
#!/bin/bash

# Functions
greet() {
    local name=$1
    echo "Hello, $name!"
}

# Error handling
set -e                    # Exit on error
trap 'echo "Error occurred"' ERR

# Command line arguments
echo "Script name: $0"
echo "First argument: $1"
echo "All arguments: $@"
echo "Number of arguments: $#"

# File testing
if [ -r "file.txt" ]; then
    echo "File is readable"
fi

# String testing
if [ "$string1" = "$string2" ]; then
    echo "Strings are equal"
fi
```

## System Administration

### Package Management

```bash
# Debian/Ubuntu
apt update                # Update package list
apt upgrade              # Upgrade packages
apt install package      # Install package
apt remove package       # Remove package
apt search package       # Search packages

# Red Hat/CentOS
yum update               # Update packages
yum install package      # Install package
yum remove package       # Remove package
yum search package       # Search packages

# Arch Linux
pacman -Syu              # Update system
pacman -S package        # Install package
pacman -R package        # Remove package
pacman -Ss package       # Search packages
```

### Service Management

```bash
# Systemd services
systemctl start service      # Start service
systemctl stop service       # Stop service
systemctl restart service    # Restart service
systemctl status service     # Check service status
systemctl enable service     # Enable service at boot
systemctl disable service    # Disable service at boot

# Traditional init scripts
service service_name start
service service_name stop
service service_name restart
```

### Log Management

```bash
# View logs
journalctl                    # Systemd journal
tail -f /var/log/syslog      # System log
tail -f /var/log/auth.log    # Authentication log

# Log rotation
logrotate -f /etc/logrotate.conf
```

## Advanced Tools

### Development Tools

```bash
# Version control
git init                    # Initialize repository
git clone url              # Clone repository
git add .                  # Stage changes
git commit -m "message"    # Commit changes
git push                   # Push to remote

# Build tools
make                       # Run makefile
cmake                      # CMake build system
autoconf                   # Autoconf configuration

# Debugging
gdb program                # GNU debugger
strace command             # Trace system calls
ltrace command             # Trace library calls
```

### Performance Analysis

```bash
# Profiling
perf record ./program      # Record performance data
perf report                # Analyze performance data

# Memory analysis
valgrind --tool=memcheck ./program
valgrind --tool=massif ./program

# System profiling
strace -c command          # Count system calls
ltrace -c command          # Count library calls
```

## Best Practices

### Security

1. **Regular updates**: Keep your system updated
2. **Strong passwords**: Use complex passwords
3. **Principle of least privilege**: Only give necessary permissions
4. **Firewall**: Configure and maintain firewall rules
5. **SSH security**: Use key-based authentication, disable root login

### Performance

1. **Monitor resources**: Regularly check system performance
2. **Optimize startup**: Disable unnecessary services
3. **Disk maintenance**: Regular filesystem checks and cleanup
4. **Memory management**: Monitor and optimize memory usage

### Maintenance

1. **Regular backups**: Implement automated backup strategies
2. **Log rotation**: Configure proper log management
3. **Disk cleanup**: Regular removal of temporary files
4. **Security audits**: Regular security assessments

## Practice Exercises

### Beginner Level

1. Navigate through your home directory using `cd` and `ls`
2. Create a directory structure with `mkdir -p`
3. Copy and move files between directories
4. Use `grep` to search for text in files
5. Practice with file permissions using `chmod`

### Intermediate Level

1. Write a shell script to automate a common task
2. Use `find` and `xargs` to process multiple files
3. Create a simple backup script
4. Practice with `sed` and `awk` for text processing
5. Monitor system processes and resources

### Advanced Level

1. Set up a web server with proper security
2. Create a monitoring and alerting system
3. Implement automated deployment scripts
4. Configure network services and firewall
5. Performance tuning and optimization

## Resources

### Books
- "The Unix Programming Environment" by Brian Kernighan and Rob Pike
- "Advanced Programming in the Unix Environment" by W. Richard Stevens
- "The Linux Command Line" by William Shotts

### Online Resources
- [Linux Documentation Project](https://tldp.org/)
- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/)
- [Linux man pages](https://man7.org/linux/man-pages/)

### Practice Platforms
- [OverTheWire Bandit](https://overthewire.org/wargames/bandit/)
- [Linux Journey](https://linuxjourney.com/)
- [Command Line Challenge](https://cmdchallenge.com/)

---

**Remember**: Unix mastery comes with practice. Start with the basics, build up gradually, and don't be afraid to experiment in a safe environment. The command line is your friend - embrace it!