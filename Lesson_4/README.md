To find the descriptions of each memory address in the microcontroller, look for the "memory map" in the data sheet.

Address 0x0000.0000 -> 0x0003.FFFF means 256kb of memory

To make LED blink, we need to find GPIO F, it is on 0x40025000, go there in the memory.

If it is blank (all "-" or "cdcd"), means it is switched off to save power, this is common practice called clock gating.

To turn memory block on, search data sheet for "clock gating".

You can find that to turn on the block, you need to enable bit 5 on:
Address: 0x400F.E000 with an offset of 0x0608, making the resulting address 0x400F.E608

In the symbolic memory view, change the "Data" on that address to 0x0000.0020, making bit 5 = 1.
