#ifndef HCPPARSER_H
# define HCPPARSER_H

# define PROTOCOL_HEADER "HCP"

enum {
	SIGNIN,
	SIGNUP,
	SIGNOUT
};

int	is_hcp(char *str);

#endif
