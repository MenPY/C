#include <mlx.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TILES 60
#define COL 15
#define ROW 15
#define WIDTH TILES * COL
#define HEIGHT TILES * ROW
#define X_EVENT_KEYPRESS 2
#define X_EVENT_EXIT 17
#define KEYCODE_EXIT 53
#define WHITE	0xFFFFFFFF
#define BLACK	0x00000000
#define RED		0x00FF0000


typedef struct s_img
{
	void *img_ptr;
	int *data;
	int bpp;
	int size_line;
	int endian;
} t_img;

typedef struct s_game
{
	void *mlx_ptr;
	void *win_ptr;
	
	t_img img;
	int map[ROW][COL];
} t_game;

int posX = 5;
int posY = 5;
int player_a;
//int player_
void draw_pixels_of_tile(t_game *game, int row, int col)
{
	int tile_row, tile_col;

	row *= TILES;
	col *= TILES;
	tile_row = 0;
	while (tile_row < TILES)
	{
		tile_col = 0;
		while (tile_col < TILES)
		{
			if (tile_row == TILES - 1 || tile_col == TILES - 1)
				game->img.data[(tile_row + row) * WIDTH + (tile_col + col)] = 0xb3b3b3;
			else
				game->img.data[(tile_row + row) * WIDTH + (tile_col + col)] = 0xFFFFFF;
			tile_col++;
		}
		tile_row++;
	}
}

void draw_tiles(t_game *game)
{
	int row, col;

	row = 0;
	while (row < ROW)
	{
		col = 0;
		while (col < COL)
		{
			if (game->map[row][col] == 1)
				draw_pixels_of_tile(game, row, col);
			col++;
		}
		row++;
	}
}

void map_init(t_game *game)
{
	int src[ROW][COL] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
	{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	memcpy(game->map, src, sizeof(int) * ROW * COL);
	draw_tiles(game);
}

void draw_player(t_game *game, int row, int col, int color)
{
	int tile_row, tile_col;

	row *= 2;
	col *= 2;
	tile_row = 0;
	while (tile_row < 10)
	{
		tile_col = 0;
		while (tile_col < 10)
		{
			if(color == 0)
				game->img.data[(tile_row + row) * WIDTH + (tile_col + col)] = RED;
			else
				game->img.data[(tile_row + row) * WIDTH + (tile_col + col)] = BLACK;
			tile_col++;
		}
		tile_row++;
	}
}

int	key_hook(int keycode, t_game *game)
{
	draw_player(game, posX, posY, 1);
	int a = game->map[posX][posY];
	printf("%d\n", a);
	if(keycode == 13)
	{
		posX -= 1;
		draw_player(game, posX, posY, 0);
	}
	else if (keycode == 2)
	{
		posY += 1;
		// if(game->map[posX][posY] == 0)
			draw_player(game, posX, posY, 0);
		//else
		//	posY -= 1;
	}
	else if (keycode == 1)
	{
		posX += 1;
		draw_player(game, posX, posY, 0);
	}
	else if (keycode == 0)
	{
		posY -= 1;
		draw_player(game, posX, posY, 0);
	}
	else if (keycode == 53)
	{
		exit(0);
	}

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, 0, 0);
	return (0);
}

void minilibx_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "Create 2D Map!");
}

void img_init(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_line, &game->img.endian);
}

int main(void)
{
    

	t_game game;

   
	minilibx_init(&game);
	img_init(&game);
	map_init(&game);
	draw_player(&game, posX, posY, 0);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img.img_ptr, 0, 0);
     
	mlx_hook(game.win_ptr, X_EVENT_KEYPRESS, 0, &key_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}


//gcc -lmlx -framework OpenGL -framework AppKit 