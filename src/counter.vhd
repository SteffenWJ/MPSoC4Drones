library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.numeric_std.ALL;

entity counter is
    Port ( clk,rst : in STD_LOGIC;
           counterValue : out std_logic_vector(31 downto 0));
end counter;

architecture Behavioral of counter is
signal count_internal: integer := 0;
signal temp_value: integer := 0;
begin
    process(clk, rst)
        begin
        if(rst='1') then
        count_internal <= 0;
        counterValue <= (others => '0');
        temp_value <= 0;
        elsif(rising_edge(clk))then
            if(count_internal+1 < 100000) then
                count_internal <= count_internal+1;
            elsif(count_internal+1 >100000) then
                count_internal <= 0;
                temp_value <= temp_value +1;
            end if;
        end if;
        counterValue <= std_logic_vector(to_unsigned(temp_value, counterValue'length));
    end process;
            
end Behavioral;
