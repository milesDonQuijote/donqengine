#ifndef HCPTYPES_H
# define HCPTYPES_H

enum {
	TELNO,
	EMAIL,
	UNAME
};

typedef struct	s_signup {
	int	id_type;
	char	*id;
	char	*password;
	char	*name;
	char	*surname;
}	t_signup;

typedef struct	s_signin {
	int	id_type;
	char	*id;
	char	*password;
}	t_signin;

typedef struct	s_signout {
	int	id_type;
	char	*id;
	char	*key;
}	t_signout;

#endif
