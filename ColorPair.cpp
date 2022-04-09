#include "ColorPair.hpp"

namespace TelCoColorCoder
{
    int getNumOfMajorColors() {
        return sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    }

    int getNumOfMinorColors() {
        return sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);
    }

    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor =
            (MajorColor)(zeroBasedPairNumber / getNumOfMinorColors());
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % getNumOfMinorColors());
        return ColorPair(majorColor, minorColor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * getNumOfMinorColors() + minor + 1;
    }

    void showColorPairManual() {
        std::cout << "\n \n ==> Displaying color pair mapping below : \n" << std::endl;
        int pairNum = 1;
        for (std::string majorColor : MajorColorNames) {
            for (std::string minorColor : MinorColorNames) {
                std::cout << pairNum++ << " = " << majorColor << " + " << minorColor << std::endl;
            }
        }
    }
}