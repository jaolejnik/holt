#include "core/bitmap.h"

int main()
{
    holt::Bitmap frame(256, 256);

    frame.save("out.png");

    return 0;
}