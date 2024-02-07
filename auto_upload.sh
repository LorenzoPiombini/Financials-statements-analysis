#!/usr/bin/expect -f

# Source directory containing JSON files
set source_dir "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests"

# Destination directory on the remote server
set destination_dir "/sites/demo/CppSoftwareDemo/"

# SSH key file
set ssh_key "/Users/stephaniepsiaki/.ssh/id_ed25519"

# SSH username and host
set ssh_username "root"
set ssh_host "167.99.159.115"

# Enter the passphrase for the SSH key
set ssh_passphrase "wl13@*67"

# List of JSON files to copy
set json_files [glob -nocomplain -directory $source_dir *.json]

foreach json_file $json_files {
    spawn scp -i $ssh_key $json_file $ssh_username@$ssh_host:$destination_dir
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
    wait
}

