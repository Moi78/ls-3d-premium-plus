#!/bin/bash

mkdir packed_game
echo "Make sure Expansion Game Engine is installed on your system ! Otherwise compile and install it (https://github.com/Moi78/ExpansionGameEngine)"
echo "Make sure you've compiled this project before !"

echo "Copying Content and Engine files..."
cp -r ./Game/Content packed_game/Content
cp -r ./Game/Engine packed_game/Engine

echo "Copying binaries"
cp ./CustomExecutable/ExGame packed_game/ls-3d-premium-plus
cp ./ls-3d-premium-plus/libls-3d-premium-plus.so packed_game/libls-3d-premium-plus.so
