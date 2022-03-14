#ifndef BCTP_H
# define BCTP_H

# define REQTYPES_LEN 3
// Request types
enum e_reqtypes{
	SIGNUP,
	SIGNIN,
	SIGNOUT,
	MESSAGE
};

// Request headers
enum e_headers {
	ID_TYPE,
	ID,
	TO_ID,
	PASSWORD,
	NAME,
	SURNAME,
	KEY,
	MESSAGE_TYPE
};

// Id types
enum e_idtype {
	TELNO,
	EMAIL,
	UNAME
};

enum	e_message {
	TEXT_T,
	IMAGE_T,
	AUDIO_T,
	VIDEO_T,
	FILE_T
};

typedef struct	s_request {
	char	request_type;
	void	*data;
}	t_request;

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

typedef struct	s_message {
	char		msg_type;
	char		id_type;
	char		*id;
	char		*key;
	char		*to_id;
	unsigned int	content_len;
	char		*content;
}	t_message;
#endif
