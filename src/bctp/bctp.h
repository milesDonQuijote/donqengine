#ifndef BCTP_H
# define BCTP_H

# define REQTYPES_LEN 3
// Request types
enum e_reqtypes{
	SIGNUP,
	SINGIN,
	SIGNOUT
};

// Request headers
enum e_headers {
	ID_TYPE,
	ID,
	PASSWORD,
	NAME,
	SURNAME,
	KEY
};

// Id types
enum e_idtype{
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
