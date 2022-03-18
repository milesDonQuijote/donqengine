#ifndef BCTP_H
# define BCTP_H

# define REQTYPES_LEN 5
// Request types
enum e_reqtypes {
	SIGNUP,
	SIGNIN,
	SIGNOUT,
	MESSAGE,
	FILE_TRANSFER
};

// Respones types
enum e_responses {
	ID_USED;
	AUTH_FAILED;
	AUTH_SUCCESS;
	FILE_FAILED;
	FILE_SUCCESS;
	DST_FOUND;
	DST_NOTFOUND;
	REQ_INVALID;
}

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
	FRAGMENT_COUNT
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

typedef struct	s_file {
	char		id_type; 
	char		*id;
	char		*to_id;
	char		*key;
	char		*file_format;
	unsigned int	file_size;
	int		fragment_count;
}	t_file;

typedef struct	s_file_stream {
	char	*key;
	char	*f_key;
	int	fragment_num;
	char	*fragment;
}

#endif
