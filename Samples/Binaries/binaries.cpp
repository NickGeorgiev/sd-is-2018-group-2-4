#include<iostream>
#include<fstream>

//'home/sdp/file.txt'
// '. ..

void readFromFile(const char* filename) {
    std::ifstream inputStream(filename, std::ios::binary);
    int extractedData;
    while(inputStream.read((char*)& extractedData, sizeof(int))){
        std::cout<<extractedData<<std::endl;
    }
    inputStream.close();
    //inputStream.open(filename)
}

void writeToBinaryFile(const char* filename){
    std::ofstream outputStream(filename, std::ios::binary);
    //outpuStream.open(filename, ios::binary)

    for(int i=0;i<10;i++){
        outputStream.write((const char*)& i, sizeof(int));
    }
    outputStream.close();
}

int main(){
    writeToBinaryFile("testBinaryFile.bin");
    readFromFile("testBinaryFile.bin");
}