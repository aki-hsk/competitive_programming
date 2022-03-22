#!/bin/bash

if [ -z "$1" ]; then
    echo "You should pass argument"
    exit 1
fi

contest_dir=$1

if [ ! -d "$contest_dir" ]; then
    echo "create contest dir"
    mkdir "$contest_dir"
fi

for ch in {a..f}
do
    if [ ! -f "./${contest_dir}/${ch}.cpp" ]; then
        echo "create ${ch}.cpp"
        cp ./codeforces_template.cpp "./${contest_dir}/${ch}.cpp"
    fi
done