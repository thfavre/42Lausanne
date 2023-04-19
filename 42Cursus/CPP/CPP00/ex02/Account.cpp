#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts),
											_amount(initial_deposit),
											_nbDeposits(0),
											_nbWithdrawals(0) {
	// ex. [19920104_091532] index:4;amount:1234;created
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created" << std::endl;
}

Account::~Account( void ) {
	// ex. [19920104_091532] index:0;amount:47;closed
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";closed" << std::endl;
	// _nbAccounts--;
	// _totalAmount -= _amount;


}

void	Account::_displayTimestamp() {
	// ex. [19920104_091532]
	std::time_t currentTime = std::time(0);
	std::tm* localTime = std::localtime(&currentTime);
	std::cout << "["
			<< std::setw(4) << std::setfill('0') << (localTime->tm_year + 1900)
			<< std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1)
			<< std::setw(2) << std::setfill('0') << localTime->tm_mday
			<< "_"
			<< std::setw(2) << std::setfill('0') << localTime->tm_hour
			<< std::setw(2) << std::setfill('0') << localTime->tm_min
			<< std::setw(2) << std::setfill('0') << localTime->tm_sec
			<< "] ";
}

void	Account::displayAccountsInfos(void) {
	// ex. [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
			<< ";total:" << _totalAmount
			<< ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals <<std::endl;

}

void	Account::displayStatus( void ) const {
	// ex. [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	// ex. [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	int	p_amount;

	p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";p_amount:" << p_amount
			<< ";deposit:" << deposit
			<< ";amount:" << _amount
			<< ";nb_deposits:"<< _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int p_amount;

	p_amount = _amount;
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		// ex. [19920104_091532] index:0;p_amount:47;withdrawal:refused
		std::cout << " index:" << _accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	// ex. [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << " index:" << _accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:"<< _nbWithdrawals <<std::endl;
	return (true);
}
