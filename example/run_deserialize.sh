if [ ! -f ./test_channel.out ]; then
    echo "Executable test_channel.out not found! Compile it ..."
    make
fi

./test_channel.out 2