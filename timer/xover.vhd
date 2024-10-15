library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
entity xover is
 port
    (
	  clk1HZ : in std_logic;
	  clk1 : out std_logic
    );
end entity xover;
architecture behave of xover is
 signal temp : std_logic;
 signal count : integer range 0 to 5000001 ;
  begin
   process(clk1HZ)
	 begin
	  if(clk1HZ'EVENT AND clk1HZ='1') then 
	   if count<499999 then
		 count <= count+1;
		else 
		 count <= 0;
		 if(temp='1') then
			temp<='0';
		 else 
		   temp<='1';
		 end if;
		end if;
	  end if;
	 clk1<=temp;
	end process;
end behave;
