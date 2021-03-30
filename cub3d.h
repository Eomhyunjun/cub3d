#ifndef CUB3D
# define CUB3D

# include <mlx.h>
# include <unistd.h>

typedef struct	s_data {
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

void			draw(t_data *data);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				create_trgb(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);


#endif
