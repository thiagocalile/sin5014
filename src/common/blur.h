/*
 Vai ser grosseiro por ser um filtro simples 5x5 para uma imagem 8 bit cinza
 */

const int gaussian_filter[5][5] = {{1, 4, 7, 4, 1},
                                             {4, 16, 26, 16, 4},
                                             {7, 26, 41, 26, 7},
                                             {4, 16, 26, 16, 4},
                                             {1, 4, 7, 4, 1}};

const int gaussian_division = 273;

int gaussian_blur(unsigned char** arr);
