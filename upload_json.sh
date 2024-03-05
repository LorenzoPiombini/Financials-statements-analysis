#!/bin/bash


# Destination directory on the remote server
destination_dir="/sites/demo/json_db"

# SSH key file
ssh_key="/Users/stephaniepsiaki/.ssh/id_ed25519"

# SSH username and host
ssh_username="root"
ssh_host="159.223.130.166"

# Enter the passphrase for the SSH key
ssh_passphrase="wl13@*67"

# List of JSON files to copy
json_files="/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/$1.json"

# Use expect within a Bash script to automate scp command
expect <<EOF
spawn scp -i $ssh_key $json_files $ssh_username@$ssh_host:$destination_dir
expect {
    "Enter passphrase for key*" {
        send "$ssh_passphrase\r"
        exp_continue
    }
    "assword:" {
        send "$ssh_password\r"
    }
    eof
}
EOF

