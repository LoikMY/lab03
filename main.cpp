#include <iostream>
#include <vector>

using namespace std;

int main(){
    size_t numer_count=0;
    cerr << "Enter number count" << endl;
    cin >> numer_count;

    vector <double> numbers;
    numbers.resize(numer_count);

    cerr << "Enter numbers" << endl;
    int i;
    for (i=0; i < numer_count; i++)
    {
        cin >> numbers[i];
    }
    size_t bin_count=0;
    cerr << "Enter bin count" << endl;
    cin >> bin_count;

    double max=numbers[0],min=numbers[0];
    for (i=0; i < numer_count; i++)
    {
       if (numbers[i] > max)
       {
           max=numbers[i];
       }
       else if (numbers[i]< min)
           min=numbers[i];
    }

    vector <size_t> bins(bin_count, 0);
    for (double number: numbers)
    {
        size_t bin_index=0;
        bin_index = ((number - min) * bin_count )/ (max-min);
        if (bin_index == bin_count)
        {
            bin_index--;
        }

            bins[bin_index]++;

    }
	vector <size_t> bins_new(bin_count, 0);
	for (i = 0; i < bin_count; i++)
	{
	size_t	height = 0;
		for (int j = 0; j <= i; j++)
		{
			height = height + bins[j];
		}
		bins_new[i] = height;
	}

    const size_t MAX=80-4;
    size_t bin_max=bins[0];
    for (i=0; i<bin_count; i++ )
        if (bins[i] > bin_max)
        bin_max = bins[i];

 double factor = 1.0;
 if (bin_max > MAX)
 {
     factor = static_cast <double> (MAX)/ bin_max;
 }

for (size_t bin:bins)
{
    size_t height = bin * factor;
    if (bin < 10)
    cout << " ";
    if (bin < 100 )
    cout << " ";

    cout << bin << '|';

    for (i=0; i< height; i++)
    {
        cout << "*";
    }
    cout << '\n';
}

    return 0;
}
