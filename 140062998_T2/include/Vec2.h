#ifndef VEC2_H
#define VEC2_H


class Vec2
{
    public:

        float x, y;

        Vec2();
        Vec2(float a, float b);
        Vec2 GetRotated(float angle);
        Vec2 operator+(Vec2 op);

      protected:


      private:
};

#endif // VEC2_H
