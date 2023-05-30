#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &f);
		Fixed(const int i);
		Fixed(const float f);

		~Fixed(void);

		Fixed	&operator=(const Fixed &f);

		bool	operator>(const Fixed &f) const;
		bool	operator<(const Fixed &f) const;
		bool	operator>=(const Fixed &f) const;
		bool	operator<=(const Fixed &f) const;
		bool	operator==(const Fixed &f) const;
		bool	operator!=(const Fixed &f) const;

		Fixed	operator+(const Fixed &f) const;
		Fixed	operator-(const Fixed &f) const;
		Fixed	operator*(const Fixed &f) const;
		Fixed	operator/(const Fixed &f) const;

		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		static			Fixed	&min(Fixed &f1, Fixed &f2);
		static const	Fixed	&min(const Fixed &f1, const Fixed &f2);
		static			Fixed	&max(Fixed &f1, Fixed &f2);
		static const	Fixed	&max(const Fixed &f1, const Fixed &f2);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_val;
		static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &f);

#endif
