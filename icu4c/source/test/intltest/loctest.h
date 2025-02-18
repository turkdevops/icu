// © 2016 and later: Unicode, Inc. and others.
// License & terms of use: http://www.unicode.org/copyright.html
/********************************************************************
 * COPYRIGHT: 
 * Copyright (c) 1997-2015, International Business Machines Corporation and
 * others. All Rights Reserved.
 ********************************************************************/

#include "intltest.h"
#include "unicode/locid.h"

/**
 * Tests for the Locale class
 **/
class LocaleTest: public IntlTest {
public:
    LocaleTest();
    virtual ~LocaleTest();
    
    void runIndexedTest( int32_t index, UBool exec, const char* &name, char* par = NULL );

    /**
     * Test methods to set and get data fields
     **/
    void TestBasicGetters(void);
    /**
     * Test methods to set and get data fields
     **/
    void TestParallelAPIValues(void);
    /**
     * Use Locale to access Resource file data and compare against expected values
     **/
    void TestSimpleResourceInfo(void);
    /**
     * Use Locale to access Resource file display names and compare against expected values
     **/
    void TestDisplayNames(void);
    /**
     * Test methods for basic object behaviour
     **/
    void TestSimpleObjectStuff(void);
    /**
     * Test methods for POSIX parsing behavior
     **/
    void TestPOSIXParsing(void);
    /**
     * Test Locale::getAvailableLocales
     **/
    void TestGetAvailableLocales(void);
    /**
     * Test methods to set and access a custom data directory
     **/
    void TestDataDirectory(void);

    void TestISO3Fallback(void);
    void TestGetLangsAndCountries(void);
    void TestSimpleDisplayNames(void);
    void TestUninstalledISO3Names(void);
    void TestAtypicalLocales(void);
#if !UCONFIG_NO_FORMATTING
    void TestThaiCurrencyFormat(void);
    void TestEuroSupport(void);
#endif
    void TestToString(void);
#if !UCONFIG_NO_FORMATTING
    void Test4139940(void);
    void Test4143951(void);
#endif
    void Test4147315(void);
    void Test4147317(void);
    void Test4147552(void);

    void Test20639_DeprecatesISO3Language();
    
    void TestVariantParsing(void);

   /* Test getting keyword enumeration */
   void TestKeywordVariants(void);
   void TestCreateUnicodeKeywords(void);

   /* Test getting keyword values */
   void TestKeywordVariantParsing(void);
   void TestCreateKeywordSet(void);
   void TestCreateKeywordSetEmpty(void);
   void TestCreateKeywordSetWithPrivateUse(void);
   void TestCreateUnicodeKeywordSet(void);
   void TestCreateUnicodeKeywordSetEmpty(void);
   void TestCreateUnicodeKeywordSetWithPrivateUse(void);
   void TestGetKeywordValueStdString(void);
   void TestGetUnicodeKeywordValueStdString(void);

   /* Test setting keyword values */
   void TestSetKeywordValue(void);
   void TestSetKeywordValueStringPiece(void);
   void TestSetUnicodeKeywordValueStringPiece(void);

   /* Test getting the locale base name */
   void TestGetBaseName(void);
    
#if !UCONFIG_NO_FORMATTING
    void Test4105828(void) ;
#endif

    void TestSetIsBogus(void);

    void TestGetLocale(void);

    void TestVariantWithOutCountry(void);

    void TestCanonicalization(void);

    void TestCanonicalize(void);

#if !UCONFIG_NO_FORMATTING
    static UDate date(int32_t y, int32_t m, int32_t d, int32_t hr = 0, int32_t min = 0, int32_t sec = 0);
#endif

    void TestCurrencyByDate(void);

    void TestGetVariantWithKeywords(void);
    void TestIsRightToLeft();
    void TestBug11421();
    void TestBug13277();
    void TestBug13554();
    void TestBug20410();
    void TestBug20900();
    void TestLocaleCanonicalizationFromFile();
    void TestKnownCanonicalizedListCorrect();
    void TestConstructorAcceptsBCP47();

    void TestAddLikelySubtags();
    void TestMinimizeSubtags();
    void TestAddLikelyAndMinimizeSubtags();

    void TestForLanguageTag();
    void TestForLanguageTagLegacyTagBug21676();
    void TestToLanguageTag();
    void TestToLanguageTagOmitTrue();

    void TestMoveAssign();
    void TestMoveCtor();

    void TestBug20407iVariantPreferredValue();

    void TestBug13417VeryLongLanguageTag();

    void TestBug11053UnderlineTimeZone();

    void TestUnd();
    void TestUndScript();
    void TestUndRegion();
    void TestUndCAPI();
    void TestRangeIterator();
    void TestPointerConvertingIterator();
    void TestTagConvertingIterator();
    void TestCapturingTagConvertingIterator();
    void TestSetUnicodeKeywordValueInLongLocale();
    void TestSetUnicodeKeywordValueNullInLongLocale();
    void TestLeak21419();
    void TestNullDereferenceWrite21597();
    void TestLongLocaleSetKeywordAssign();
    void TestLongLocaleSetKeywordMoveAssign();

private:
    void _checklocs(const char* label,
                    const char* req,
                    const Locale& validLoc,
                    const Locale& actualLoc,
                    const char* expReqValid="gt",
                    const char* expValidActual="ge"); 

    /**
     * routine to perform subtests, used by TestDisplayNames
     **/
    void doTestDisplayNames(Locale& inLocale, int32_t compareIndex);
    /**
     * additional intialization for datatables storing expected values
     **/
    void setUpDataTable(void);

    UnicodeString** dataTable;
    
    enum {
        ENGLISH = 0,
        FRENCH = 1,
        CROATIAN = 2,
        GREEK = 3,
        NORWEGIAN = 4,
        ITALIAN = 5,
        XX = 6,
        CHINESE = 7,
        MAX_LOCALES = 7
    };

    enum {
        LANG = 0,
        SCRIPT,
        CTRY,
        VAR,
        NAME,
        LANG3,
        CTRY3,
        LCID,
        DLANG_EN,
        DSCRIPT_EN,
        DCTRY_EN,
        DVAR_EN,
        DNAME_EN,
        DLANG_FR,
        DSCRIPT_FR,
        DCTRY_FR,
        DVAR_FR,
        DNAME_FR,
        DLANG_CA,
        DSCRIPT_CA,
        DCTRY_CA,
        DVAR_CA,
        DNAME_CA,
        DLANG_EL,
        DSCRIPT_EL,
        DCTRY_EL,
        DVAR_EL,
        DNAME_EL,
        DLANG_NO,
        DSCRIPT_NO,
        DCTRY_NO,
        DVAR_NO,
        DNAME_NO
    };

#if !UCONFIG_NO_COLLATION
    /**
     * Check on registered collators.
     * @param expectExtra if non-null, the locale ID of an 'extra' locale that is registered.
     */
    void checkRegisteredCollators(const char *expectExtra = NULL);
#endif
};
