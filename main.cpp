#include <iostream>
#include <vector>
#include "histogram.h"

using namespace std;

    vector<double> input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

    vector<size_t> make_histogram(vector<double> numbers, size_t bin_count) {
    vector<size_t> result (bin_count);

    double min, max;
    find_minmax(numbers, min, max);
    for (double number : numbers) {
        size_t bin = (size_t)((number - min) / (max - min) * bin_count);
        if (bin == bin_count) {
            bin--;
        }
        result[bin]++;
    }
    return result;
}


void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg width='" << width << "' height='" << height << "' "
         << "viewBox='0 0 " << width << " " << height << "' "
         << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end() {
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text){
cout << "<text x='" << left << "' y='" <<baseline <<"'>"<<text <<"</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke = "black" , string fill = "black" ){
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill <<"'  />";
}

void
show_histogram_svg(const vector<size_t>& bins) {

    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    double top = 0;
    for (size_t bin : bins) {
        const double bin_width = 10 * bin;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        string stroke="black";
        string fill="orange";
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, stroke, fill );
        top += BIN_HEIGHT;
    }

    svg_end();
}

int main() {
    // ���� ������
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const vector<double> & numbers = input_numbers(number_count);


    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    // ��������� ������

    const auto bins = make_histogram(numbers, bin_count);

    // ����� ������

    show_histogram_svg(bins);


    return 0;
}
