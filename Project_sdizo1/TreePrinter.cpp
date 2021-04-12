#include "TreePrinter.h"



std::string TreePrinter::do_padding(unsigned index, unsigned mlength) {
    std::string padding;
    if (int((index - 1) / 2) != 0) {
        return (int((index - 1) / 2) % 2 == 0) ?
            (do_padding(int((index - 1) / 2), mlength) + std::string(mlength + 4, ' ') + " ") :
            (do_padding(int((index - 1) / 2), mlength) + std::string(mlength + 3, ' ') + " |");
    }
    return padding;
}


void TreePrinter::print(std::vector<int> const& tree, unsigned index, unsigned mlength) {
    auto last = tree.size() - 1;
    auto  left = 2 * index + 1;
    auto  right = 2 * index + 2;
    std::cout << " " << tree[index] << " ";
    if (left <= last) {
        auto llength = std::to_string(tree[left]).size();
        std::cout << "---" << std::string(mlength - llength, '-');
        print(tree, left, mlength);
        if (right <= last) {
            auto rlength = std::to_string(tree[right]).size();
            std::cout << "\n" << do_padding(right, mlength) << std::string(mlength + 3, ' ') << " | ";
            std::cout << "\n" << do_padding(right, mlength) << std::string(mlength + 3, ' ') << " └" <<
                std::string(mlength - rlength, '-');
            print(tree, right, mlength);
        }
    }
}