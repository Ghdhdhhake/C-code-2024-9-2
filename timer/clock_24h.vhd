library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_unsigned.ALL;
entity clock_24h is
	port (
			clk1ms : in std_logic;
			rst1,en1 : in std_logic;
			smg1,smg2,smg3,smg4,smg5,smg6 : out std_logic_vector(6 downto 0);
			cout : out std_logic
			);
end  entity clock_24h;
architecture Behavioral of clock_24h is
--引用
   component xover
		 port
		 (
		  clk1HZ : in std_logic;
		  clk1 : out std_logic
		 );
	end component;
	component count24
		PORT (
   		 CLK,RST,EN:IN STD_LOGIC;
   		 DHOUT:BUFFER STD_LOGIC_VECTOR(3 DOWNTO 0); --高四位输出
    	    DLOUT:BUFFER STD_LOGIC_VECTOR(3 DOWNTO 0); --低四位输出
         COUT:OUT STD_LOGIC);
	end component;
	component count60
		PORT (
   		 CLK,RST,EN:IN STD_LOGIC;
   		 DHOUT:BUFFER STD_LOGIC_VECTOR(3 DOWNTO 0); --高四位输出
    	    DLOUT:BUFFER STD_LOGIC_VECTOR(3 DOWNTO 0); --低四位输出
         COUT:OUT STD_LOGIC);
	end component;
	component smg
	PORT (INDATA: IN STD_LOGIC_VECTOR(3 DOWNTO 0); 
		  ODATA: OUT STD_LOGIC_VECTOR(6 DOWNTO 0));
	end component;
	signal  d,e,f,g :STD_LOGIC;
	signal  a,b,k,l,n,m :std_logic_vector(3 downto 0);
begin
   U1 :xover port map(clk1HZ=>clk1ms, clk1=>d);
	U2 :count60 port map(CLK=>d,RST=>rst1,EN=>en1, COUT=>e,DHOUT=>k,DLOUT=>l);
	U3 :count60 port map(CLK=>e,RST=>rst1,EN=>en1, COUT=>f,DHOUT=>n,DLOUT=>m);
	U4 :count24 port map(CLK=>f,RST=>rst1,EN=>en1, COUT=>cout,DHOUT=>a,DLOUT=>b);	
	USL : smg   port map(INDATA=>l ,ODATA=>smg1);
   USH : smg   port map(INDATA=>k ,ODATA=>smg2);
	UML : smg   port map(INDATA=>m ,ODATA=>smg3);
	UMH : smg   port map(INDATA=>n ,ODATA=>smg4);
	UHL : smg   port map(INDATA=>a ,ODATA=>smg5);
	UHH : smg   port map(INDATA=>b ,ODATA=>smg6);
end Behavioral;
