#ifndef ENEMIGOS_H
#define ENEMIGOS_H


class enemigos
{
    public:


            int pos_x;
            int pos_y;
            string name;
            string tipo;
            int velocidad_x,velocidad_y;
            enemigos(int pos_x, int pos_y, string name, string tipo, int velocidad_x, int velocidad_y);

        enemigos();
        virtual ~enemigos();
        void moverse();
    protected:
    private:
};

#endif // ENEMIGOS_H
