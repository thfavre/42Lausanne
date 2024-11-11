#!/bin/bash

# Check for directory argument
if [ -z "$1" ]; then
    echo "❌ Usage: $0 <directory>"
    exit 1
fi

directory="$1"

# Check if the directory exists
if [ ! -d "$directory" ]; then
    echo "❌ Error: Directory '$directory' does not exist."
    exit 1
fi

# Initialize counters
success_count=0
total_count=0

# Iterate over ELF files in the directory
echo "🔍 Testing ELF files in directory: $directory"
for file in "$directory"/*; do
    if file "$file" | grep -q 'ELF'; then
        ((total_count++))
        echo "🗂️  Testing file: $file"
        # Run the original nm and ft_nm, then compare their output
        ./ft_nm "$file" > ft_nm_output.txt
        nm "$file" > nm_output.txt

        # Show the difference between the outputs
        diff_output=$(diff -u nm_output.txt ft_nm_output.txt)
        if [ -n "$diff_output" ]; then
            echo "⚠️  Differences found in $file:"
            echo "$diff_output"
        else
            echo "✅ No differences found in $file"
            ((success_count++))
        fi

        echo # Add blank line after each test
    else
        echo "⏭️  Skipping non-ELF file: $file"
        echo # Add blank line after each non-ELF file
    fi
done

# Cleanup
rm -f ft_nm_output.txt nm_output.txt

# Summary
echo "🏁 Testing complete!"
echo "Summary: $success_count / $total_count files passed."
