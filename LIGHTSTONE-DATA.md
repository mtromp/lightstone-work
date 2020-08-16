# Lightstone Data

I found some discrepancies in the data documentation from liblightstone and
the actual code. I compared this also to the C# code that I found for the
Lightstone monitor:

- The first 4 characters of a <RAW> block are associated with Skin Conductance.
- The second 4 characters of a <RAW> block are associated with Heart Rate
  Variability
- For each 4 characters, convert the first 2 into a byte and the second 2 into
  an integer byte.
  - "0202" becomes two bytes each containing the value 2
  - "021A" becomes a byte with value 2 and a byte of value 26
- The first byte is shifted 8 places, or multiplied by 255(?)[found in C# code]
- The second byte is added to the first byte.
  - "021A" First byte becomes 512. Add 26 => 538
- The skin conductance value is multiplied by .01. Result: 5.38
- The heart rate variability value is multiplied by .001. Result: 0.538

According to some sources, the actual range for Skin Conductance is: 3.0 - 15.0

According to some sources,  the actual range for Heart Rate Variability is:
1.6 - 2.5 (the example above is using a skin conductance value).

When the sensors have no fingers in them, then: HRV ~= 2.0 and SCL ~= 0.17
