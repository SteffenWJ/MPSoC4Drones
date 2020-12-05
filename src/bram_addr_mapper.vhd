library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_arith.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity bram_addr_mapper is
    generic( n_addr_bits : positive range 1 to 29   :=  8);
    port( 
        addr_in     :   in  std_logic_vector(n_addr_bits-1 downto 0);
        n_rst_in    :   in  std_logic;
        wr_in       :   in  std_logic;
        addr_out    :   out std_logic_vector(31 downto 0);
        rst_out     :   out std_logic;
        wr_out      :   out std_logic_vector(3 downto 0)
    );
end bram_addr_mapper;

architecture Behavioral of bram_addr_mapper is
begin

    addr_out(1 downto 0)                <=  "00";
    addr_out(n_addr_bits+1 downto 2)    <=  addr_in;
    addr_out(31 downto n_addr_bits+2)   <=  (others => '0');
    rst_out                             <=  not n_rst_in;
    wr_out                              <=  (others => wr_in);

end Behavioral;
