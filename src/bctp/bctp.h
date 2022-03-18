#ifndef BCTP_H
# define BCTP_H

# define REQTYPES_LEN 4
// Request types
enum e_reqtypes{
	SIGNUP,
	SIGNIN,
	SIGNOUT,
	MESSAGE,
	FILE_TRANSFER
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
	MESSAGE_TYPE,
	FILE_FORMAT,
	FILE_SIZE,
	PEACE_COUNT
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
	char		*file_format;
	char		id_type;
	char		*id;
	char		*key;
	char		*to_id;
	unsigned int	content_len;
	char		*content;
}	t_message;

struct typedef	s_file {
	char		id_type; 
	char		*id;
	char		*to_id;
	char		*key;
	char		*file_format;
	unsigned int	file_size;
	int		peace_count;
}	t_file;
#endif
