TEMPLATE_INSTRUCTION_HELPER(sar) {
    int32_t bits = ctx.operands[1].getUnsignedValue() & 0x1f;
    int32_t value = ctx.operands[0].getUnsignedValue();
    size_t size = ctx.operands[0].size;
    uint32_t result = value >> bits;
    ctx.operands[0].setValue(result);
    if (bits) {
        cpu.sf = result >> (size * 8 - 1);
        cpu.zf = result == 0;
        cpu.pf = calc_pf(result);
        cpu.cf = value >> (bits - 1);
    }
    if (bits == 1) cpu.of = 0;
    print_instr(ctx, "sar");
}
