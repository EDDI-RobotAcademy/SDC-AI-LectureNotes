#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 <path_to_source> <path_to_target>"
    exit 1
fi

source_directory="$1"
target_directory="$2"

echo "source: $1"
echo "target: $2"

mkdir -p ${target_directory}

folder_names=($(find "${source_directory}" -mindepth 1 -maxdepth 1 -type d -exec basename {} \;))

for folder in "${folder_names[@]}"; do
    echo "folder: ${folder}"
    prepare_file="${target_directory}/${folder}/prepare.txt"
    mkdir -p "${target_directory}/${folder}"
    echo "Prepare" > "${prepare_file}"
done

echo "Operation completed successfully!"
