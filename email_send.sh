#!/bin/bash

message=$1
bcc_addresses=$2 # The second argument is a comma-separated string of email addresses
# Decode the message
message=$(echo "$encodedMessage" | base64 --decode)
{
    echo "From: important.update@whitepaper-info.com"
    echo "to:"
    echo "Bcc: $bcc_addresses"
    echo "Subject: Senator transaction update."
    echo "$message"
} | sendmail -t
