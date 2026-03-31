#include <iostream>
#include "MemoryRiver.hpp"
using namespace std;

struct TestData {
    int id;
    double value;
    char name[20];
};

int main() {
    // Test basic functionality
    MemoryRiver<TestData, 3> river("test_data.bin");

    // Initialize the file
    river.initialise();

    // Write info to header
    river.write_info(100, 1);
    river.write_info(200, 2);
    river.write_info(300, 3);

    // Read info from header
    int info1, info2, info3;
    river.get_info(info1, 1);
    river.get_info(info2, 2);
    river.get_info(info3, 3);

    cout << "Info values: " << info1 << " " << info2 << " " << info3 << endl;

    // Write some data
    TestData data1 = {1, 3.14, "First"};
    TestData data2 = {2, 2.71, "Second"};
    TestData data3 = {3, 1.41, "Third"};

    int index1 = river.write(data1);
    int index2 = river.write(data2);
    int index3 = river.write(data3);

    cout << "Indices: " << index1 << " " << index2 << " " << index3 << endl;

    // Read data back
    TestData read_data;
    river.read(read_data, index2);
    cout << "Read data: " << read_data.id << " " << read_data.value << " " << read_data.name << endl;

    // Update data
    TestData updated_data = {2, 9.99, "Updated"};
    river.update(updated_data, index2);

    // Read updated data
    river.read(read_data, index2);
    cout << "Updated data: " << read_data.id << " " << read_data.value << " " << read_data.name << endl;

    return 0;
}
