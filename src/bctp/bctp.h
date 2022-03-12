#ifndef BCTP_H
# define BCTP_H

// Request types
enum {
	SIGNUP,
	SINGIN,
	SIGNOUT
};

// Sign up headers
enum {
	ID_TYPE,
	ID,
	PASSOWRD,
	NAME,
	SURNAME
};

// Sign in headers
enum {
	ID_TYPE,
	ID,
	PASSOWRD
};

// Sign out headers
enum {
	ID_TYPE,
	ID,
	KEY
};

// Id types
enum {
	TELNO,
	EMAIL,
	UNAME
};

typedef struct	s_parsed_request {
	char	request_type;
	void	*data;
}	t_parsed_request;

typedef struct	s_signup {
	char	id_type;
	char	*id;
	char	*password;
	char	*name;
	char	*surname;
}	t_signup;

typedef struct	s_signin {
	char	id_type;
	char	*id;
	char	*password;
}	t_signin;

typedef struct	s_signout {
	char	id_type;
	char	*id;
	char	*key;
}	t_signout;
#endif
