# Unix Practice Exercises 🚀

## Getting Started

Before you begin these exercises, make sure you have a Unix-like environment. You can use:
- Linux (Ubuntu, CentOS, etc.)
- macOS Terminal
- WSL (Windows Subsystem for Linux)
- A cloud-based Linux server

## Exercise 1: File System Navigation (Beginner)

### Objective
Learn basic file system navigation commands.

### Tasks
1. **Check your current location**
   ```bash
   pwd
   ```

2. **List files in current directory**
   ```bash
   ls
   ls -la
   ```

3. **Navigate to your home directory**
   ```bash
   cd ~
   pwd
   ```

4. **Create a practice directory structure**
   ```bash
   mkdir -p unix_practice/{files,scripts,backups}
   cd unix_practice
   ls -la
   ```

5. **Navigate through the structure**
   ```bash
   cd files
   pwd
   cd ..
   cd scripts
   pwd
   cd ..
   ```

### Expected Output
You should see a directory structure like:
```
unix_practice/
├── files/
├── scripts/
└── backups/
```

## Exercise 2: File Operations (Beginner)

### Objective
Practice creating, copying, moving, and deleting files.

### Tasks
1. **Create some test files**
   ```bash
   cd ~/unix_practice/files
   echo "Hello World" > hello.txt
   echo "This is a test file" > test.txt
   echo "Another file for practice" > practice.txt
   ls -la
   ```

2. **Copy files**
   ```bash
   cp hello.txt hello_backup.txt
   cp test.txt ../backups/
   ls -la
   ls ../backups/
   ```

3. **Move and rename files**
   ```bash
   mv practice.txt ../scripts/
   mv hello.txt hello_world.txt
   ls -la
   ls ../scripts/
   ```

4. **View file contents**
   ```bash
   cat hello_world.txt
   head -2 test.txt
   tail -1 hello_backup.txt
   ```

5. **Clean up (optional)**
   ```bash
   rm hello_backup.txt
   ls -la
   ```

## Exercise 3: Text Processing (Intermediate)

### Objective
Learn to use grep, sed, awk, and other text processing tools.

### Tasks
1. **Create a sample data file**
   ```bash
   cd ~/unix_practice/files
   cat > users.txt << EOF
   john:developer:25:john@example.com
   sarah:manager:32:sarah@example.com
   mike:developer:28:mike@example.com
   lisa:designer:29:lisa@example.com
   david:developer:35:david@example.com
   EOF
   ```

2. **Search with grep**
   ```bash
   grep "developer" users.txt
   grep -i "sarah" users.txt
   grep -v "developer" users.txt
   ```

3. **Process with awk**
   ```bash
   awk -F: '{print $1, $2}' users.txt
   awk -F: '$3 > 30 {print $1, $3}' users.txt
   awk -F: '{sum += $3} END {print "Average age:", sum/NR}' users.txt
   ```

4. **Edit with sed**
   ```bash
   sed 's/developer/engineer/g' users.txt
   sed -i 's/example.com/company.com/g' users.txt
   cat users.txt
   ```

5. **Sort and filter**
   ```bash
   sort users.txt
   sort -t: -k3 -n users.txt  # Sort by age
   cut -d: -f1,4 users.txt | sort
   ```

## Exercise 4: Process Management (Intermediate)

### Objective
Learn to monitor and control processes.

### Tasks
1. **Check system processes**
   ```bash
   ps aux | head -10
   ps -ef | grep bash
   ```

2. **Monitor system resources**
   ```bash
   top -n 1
   free -h
   df -h
   ```

3. **Create background processes**
   ```bash
   sleep 60 &
   jobs
   ps aux | grep sleep
   ```

4. **Control processes**
   ```bash
   kill %1  # Kill the first background job
   jobs
   ```

5. **System information**
   ```bash
   uname -a
   cat /etc/os-release
   lscpu | head -10
   ```

## Exercise 5: Shell Scripting (Advanced)

### Objective
Write and execute shell scripts.

### Tasks
1. **Create a simple script**
   ```bash
   cd ~/unix_practice/scripts
   cat > system_info.sh << 'EOF'
   #!/bin/bash
   
   echo "=== System Information ==="
   echo "Date: $(date)"
   echo "User: $(whoami)"
   echo "Hostname: $(hostname)"
   echo "Current directory: $(pwd)"
   echo "Disk usage:"
   df -h | head -5
   EOF
   ```

2. **Make it executable and run**
   ```bash
   chmod +x system_info.sh
   ./system_info.sh
   ```

3. **Create a more advanced script**
   ```bash
   cat > file_analyzer.sh << 'EOF'
   #!/bin/bash
   
   if [ $# -eq 0 ]; then
       echo "Usage: $0 <directory>"
       exit 1
   fi
   
   target_dir="$1"
   
   if [ ! -d "$target_dir" ]; then
       echo "Error: $target_dir is not a directory"
       exit 1
   fi
   
   echo "=== File Analysis for $target_dir ==="
   echo "Total files: $(find "$target_dir" -type f | wc -l)"
   echo "Total directories: $(find "$target_dir" -type d | wc -l)"
   echo "Largest file: $(find "$target_dir" -type f -exec ls -lh {} + | sort -k5 -hr | head -1 | awk '{print $9, $5}')"
   EOF
   ```

4. **Test the advanced script**
   ```bash
   chmod +x file_analyzer.sh
   ./file_analyzer.sh ~/unix_practice
   ```

## Exercise 6: Networking (Intermediate)

### Objective
Learn basic networking commands and concepts.

### Tasks
1. **Check network configuration**
   ```bash
   ip addr show
   ip route show
   hostname -I
   ```

2. **Test connectivity**
   ```bash
   ping -c 3 8.8.8.8
   ping -c 3 google.com
   ```

3. **Check network services**
   ```bash
   ss -tuln | head -10
   netstat -tuln | head -10
   ```

4. **DNS operations**
   ```bash
   nslookup google.com
   dig google.com +short
   host google.com
   ```

5. **Download files**
   ```bash
   cd ~/unix_practice/files
   curl -o sample.html https://httpbin.org/html
   wget https://httpbin.org/json -O sample.json
   ls -la
   ```

## Exercise 7: Advanced File Operations (Advanced)

### Objective
Master advanced file operations and find command.

### Tasks
1. **Create a complex directory structure**
   ```bash
   cd ~/unix_practice
   mkdir -p projects/{web,api,docs}/{src,tests,config}
   touch projects/web/src/index.html
   touch projects/api/src/main.py
   touch projects/docs/src/README.md
   ```

2. **Use find command**
   ```bash
   find . -name "*.py"
   find . -type f -mtime -1
   find . -size +1k
   find . -user $(whoami)
   ```

3. **Combine find with other commands**
   ```bash
   find . -name "*.txt" -exec wc -l {} \;
   find . -type f -exec grep -l "src" {} \;
   find . -name "*.sh" -exec chmod +x {} \;
   ```

4. **Advanced file operations**
   ```bash
   # Create a backup with timestamp
   tar -czf backup_$(date +%Y%m%d_%H%M%S).tar.gz projects/
   
   # Extract and verify
   tar -tzf backup_*.tar.gz
   ```

## Exercise 8: System Administration (Advanced)

### Objective
Learn basic system administration tasks.

### Tasks
1. **Check system logs**
   ```bash
   journalctl -n 20
   tail -20 /var/log/syslog 2>/dev/null || echo "Log file not accessible"
   ```

2. **Check system services**
   ```bash
   systemctl list-units --type=service --state=running | head -10
   systemctl status ssh 2>/dev/null || echo "SSH service not found"
   ```

3. **User and group information**
   ```bash
   id
   groups
   who
   w
   ```

4. **Package management (if available)**
   ```bash
   # For Debian/Ubuntu
   apt list --installed | head -10 2>/dev/null || echo "apt not available"
   
   # For Red Hat/CentOS
   yum list installed | head -10 2>/dev/null || echo "yum not available"
   ```

## Exercise 9: Performance Monitoring (Advanced)

### Objective
Learn to monitor system performance.

### Tasks
1. **Real-time monitoring**
   ```bash
   # Run these in separate terminals or background
   top -d 1 -n 5
   iostat 1 5 2>/dev/null || echo "iostat not available"
   vmstat 1 5 2>/dev/null || echo "vmstat not available"
   ```

2. **Process analysis**
   ```bash
   ps aux --sort=-%cpu | head -10
   ps aux --sort=-%mem | head -10
   ```

3. **System resource usage**
   ```bash
   free -h
   df -h
   du -h ~/unix_practice | sort -hr
   ```

## Exercise 10: Automation Project (Expert)

### Objective
Create a comprehensive automation script.

### Tasks
1. **Create a system maintenance script**
   ```bash
   cd ~/unix_practice/scripts
   cat > maintenance.sh << 'EOF'
   #!/bin/bash
   
   LOG_FILE="/tmp/maintenance_$(date +%Y%m%d_%H%M%S).log"
   
   log() {
       echo "$(date '+%Y-%m-%d %H:%M:%S') - $1" | tee -a "$LOG_FILE"
   }
   
   log "Starting system maintenance"
   
   # Check disk usage
   log "Checking disk usage..."
   df -h | tee -a "$LOG_FILE"
   
   # Check memory usage
   log "Checking memory usage..."
   free -h | tee -a "$LOG_FILE"
   
   # Check running processes
   log "Top 10 processes by CPU usage..."
   ps aux --sort=-%cpu | head -10 | tee -a "$LOG_FILE"
   
   # Check system load
   log "System load average..."
   uptime | tee -a "$LOG_FILE"
   
   # Create backup of practice directory
   log "Creating backup..."
   cd ~
   tar -czf "unix_practice_backup_$(date +%Y%m%d_%H%M%S).tar.gz" unix_practice/
   
   log "Maintenance completed. Log saved to: $LOG_FILE"
   EOF
   ```

2. **Make it executable and run**
   ```bash
   chmod +x maintenance.sh
   ./maintenance.sh
   ```

3. **Schedule it to run automatically**
   ```bash
   # Add to crontab (runs every day at 2 AM)
   (crontab -l 2>/dev/null; echo "0 2 * * * ~/unix_practice/scripts/maintenance.sh") | crontab -
   crontab -l
   ```

## Challenge Exercises

### Challenge 1: Log Analyzer
Create a script that analyzes system logs and reports:
- Most frequent error messages
- Peak usage times
- Failed login attempts

### Challenge 2: Network Monitor
Create a script that:
- Monitors network connectivity
- Alerts when services are down
- Generates network usage reports

### Challenge 3: Backup System
Create an automated backup system that:
- Backs up specified directories
- Rotates old backups
- Verifies backup integrity
- Sends notifications

## Tips for Success

1. **Start small**: Begin with basic commands and gradually increase complexity
2. **Practice regularly**: Use these commands in your daily work
3. **Read man pages**: Use `man command` to learn more about each command
4. **Experiment safely**: Always test commands in a safe environment
5. **Document your learning**: Keep notes of useful commands and techniques

## Next Steps

After completing these exercises:
1. Explore more advanced topics like kernel modules, device drivers
2. Learn about containerization (Docker, Kubernetes)
3. Study cloud platforms and automation tools
4. Practice with real-world scenarios and projects
5. Contribute to open-source projects

Remember: Unix mastery is a journey, not a destination. Keep practicing and exploring!