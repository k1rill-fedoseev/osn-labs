if [[ ! -f "nums.txt" ]]; then
    echo "1" > "nums.txt"
fi

while true; do
    if ln "nums.txt" "nums.lock" 2> /dev/null ; then
        n=$(cat "nums.txt" | tail -n 1)
        echo "$((n + 1))" >> nums.txt
        rm "nums.lock"
    fi
done