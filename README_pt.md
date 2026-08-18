> *Este projeto foi criado como parte do currículo da 42 por **nde-sant** e **aletude-***

---

## Descrição
Neste projeto temos o objetivo de construir um pequeno motor gráfico em raycasting,
nos moldes do clássico Wolfenstein 3D. A partir de um mapa descrito em um arquivo de
configuração (`.cub`), o programa renderiza uma cena 3D em tempo real, permitindo que o
jogador se mova e olhe ao redor dentro do labirinto. Para esta implementação utilizamos a
biblioteca gráfica [MLX42](https://github.com/codam-coding-college/MLX42).

## Funcionalidades Disponíveis
- Parsing e validação completa de arquivos `.cub` (texturas, cores de chão/teto, grid do mapa);
- Raycasting via DDA (Digital Differential Analysis) para renderização das paredes;
- Texturas distintas para cada orientação de parede (Norte, Sul, Leste, Oeste);
- Movimentação do jogador (frente, trás, strafe esquerda/direita);
- Rotação de câmera por teclado e por mouse;
- Minimapa exibido em tempo real;
- Detecção de colisão com as paredes do mapa.

## Instruções
Clone o repositório e entre na pasta:
``` bash
git clone https://github.com/nicolasgsantana/cub3D.git
cd cub3D
```
Compile e execute o programa, passando um mapa `.cub` como argumento:
``` bash
make
./cub3D maps/map.cub
```

### Teste livremente!
Alguns mapas de exemplo já estão disponíveis na pasta `maps/`:
```bash
./cub3D maps/map_subject.cub
```
```bash
./cub3D maps/maze.cub
```
```bash
./cub3D maps/rooms.cub
```

### Controles
- `W` `A` `S` `D`: movimentação;
- `←` `→` ou mouse: rotação da câmera;
- `M`: alterna mouse ativo;
- `ESC`: sair do jogo.

## Recursos
Referências utilizadas durante o desenvolvimento:

- [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html);
- [MLX42 Documentation](https://github.com/codam-coding-college/MLX42);
- [Serie Make your own Raycaster do canal 3D Sage](https://youtu.be/gYRrGTC7GtA);
- [Video Raycasting in C - from Scratch do Daniel Hirsch](https://youtu.be/2IEUa2gYJHQ);
- A IA foi utilizada para:
  - realizar testes isolados
  - debugging

[English](https://github.com/nicolasgsantana/cub3D/blob/main/README.md) | *Português*
