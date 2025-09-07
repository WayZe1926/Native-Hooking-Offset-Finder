noobshit = 0;
			ofstream outfile;
			outfile.open("hook all dump.txt");
			outfile << "//uintptr_t HookAll[6932];" << std::endl;
			for (auto natives : native_address_dump)
			{
				
				noobshit = noobshit + 1;
					uint64_t addresses = (uint64_t)get_handler(natives.hash);
					outfile << "HookAll" << "[" << std::dec << noobshit << std::dec << "] = ";
					outfile << "(" << std::hex << "0x" << std::hex << (addresses - uintptr_t(GetModuleHandleA(0))) << " + uintptr_t(GetModuleHandleA(0))" << ")" <<";" << endl;					
			}
			outfile.close();