#ifndef RECT_H
#define RECT_H


class Rect
{
      public:
        float x, y, w, h;

        Rect();
        Rect(float a, float b, float c, float d);

        bool Contains(float valueX, float valueY);


      protected:


      private:

};

#endif // RECT_H
