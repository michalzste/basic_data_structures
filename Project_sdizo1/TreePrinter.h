#pragma once
#include <vector>
#include <string>
#include<iostream>
class TreePrinter
{

public:
    std::string do_padding(unsigned index, unsigned mlength);
    void print(std::vector<int> const& tree, unsigned index, unsigned mlength);
};
