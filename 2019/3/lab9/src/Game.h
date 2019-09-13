#ifndef GAME_H
#define GAME_H

class Game {
  private:
    int dinero;
    int vida;
    int max_vida;
    int nivel;
    bool batalla;

    int vida_oponente;

    bool hilo_batalla;
    bool hilo_dinero;
    bool hilo_vida;

  public:
    Game();

    int getVida();
    int getVidaOp();

    bool play(int);
    bool busy();
    void comprar_cura();
    void print_info();
    void stop();

    static void runner_batalla(void *);
    void run_batalla();
    void call_batalla();
    void empezar_batalla();

    static void runner_dinero(void *);
    void run_dinero();
    void call_dinero();

    static void runner_vida(void *);
    void run_vida();
    void call_vida();
};

#endif
