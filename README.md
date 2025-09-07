# Native-Hooking-Offset-Finder
https://i.ibb.co/b58bdfcz/image-2025-09-07-133630473.jpg
Edit : Some extra info. Dumper crashes when reaching HookAllArraySize[2918] which is NETWORK::GET_NETWORK_TIME. I continued my search at 3000 and was working fine.

I was super annoyed by the idea of having to manually search for natives to hook again once mine got patched that i came up with this little idea of searching for them automaticly.
Code is shared below.
I guess this could be alot cleaner and and probally someone out there has a better method then the noob method im using by dumping it to an entire array first, but [removed] it i cooked this up a few hours after i got the idea.
It might eventually crash cause it creates too many hooks even though i disable and remove them.

With current settings entire search takes 115 minutes (almost 2 hours)[DEPENDING ON YOUR HOOKING TICKRATE], you can edit the max value to win time if you really wanna scan them all but this will come at a price of being less confident the native is actually good for hooking.

I suggest to dump the list, look up a native section you wanna "scan" for compatible natives and start at that HookAllArraySize.


Some natives dumped (checked first 850 natives) [SHOULD WORK FOR HOOKING]
https://pastebin.com/TUyQmcqj (i used godmode and never wanted while dumping, so they are in the list but cant be used)

Matching crossmap for link above (use this to find the natives for hooking above incase game updates):
https://www.unknowncheats.me/forum/2841943-post372.html

Dumper list:
https://pastebin.com/itrkRtDQ
Dumped Array list (using dumper above)
https://pastebin.com/A8fWhujb
Obviously you can use all the int's to display ingame how many you searched and how many you found. ill post a pic of mine in a bit. //EDIT = ADDED PIC
