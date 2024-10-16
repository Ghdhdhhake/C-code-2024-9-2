LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
ENTITY count24 IS --24进制计数器
	PORT (
   		 CLK,RST,EN:IN STD_LOGIC;
   		 DHOUT:BUFFER STD_LOGIC_VECTOR(3 DOWNTO 0); 
    	    DLOUT:BUFFER STD_LOGIC_VECTOR(3 DOWNTO 0); 
         COUT:OUT STD_LOGIC);
END ENTITY count24;
ARCHITECTURE behave OF count24 IS
BEGIN
   COUT<='1'WHEN(DHOUT="0010" AND DLOUT="0011")ELSE '0'; --确定进位条件
	PROCESS(CLK,EN,RST)
	BEGIN
	      IF RST='1' THEN DHOUT<="0000";DLOUT<="0000"; --异步清零
	      ELSIF CLK'EVENT AND CLK ='1' THEN 
			IF EN='1' THEN DLOUT<=DLOUT+1;END IF;   --同步使能
			IF(DLOUT=9)THEN DLOUT<="0000";DHOUT<=DHOUT+1;END IF;  --低四位归零设置
	       IF(DHOUT=2 AND DLOUT=3) THEN DHOUT<="0000"; END IF; --高四位归零设置
			  END IF;
END PROCESS;
END ARCHITECTURE behave;