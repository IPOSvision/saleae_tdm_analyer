#ifndef TDM_ANALYZER_RESULTS
#define TDM_ANALYZER_RESULTS

#include <AnalyzerResults.h>

class TdmAnalyzer;
class TdmAnalyzerSettings;

enum TdmResultType
{
    // leave numerical space for channels, frame mType is limited to 8 bits
    // which this is stored in, so keep the max number below 255
    ErrorTooFewBits = 128,
    ErrorDoesntDivideEvenly
};


class TdmAnalyzerResults : public AnalyzerResults
{
  public:
    TdmAnalyzerResults( TdmAnalyzer* analyzer, TdmAnalyzerSettings* settings );
    virtual ~TdmAnalyzerResults();

    virtual void GenerateBubbleText( U64 frame_index, Channel& channel, DisplayBase display_base );
    virtual void GenerateExportFile( const char* file, DisplayBase display_base, U32 export_type_user_id );

    virtual void GenerateFrameTabularText( U64 frame_index, DisplayBase display_base );
    virtual void GeneratePacketTabularText( U64 packet_id, DisplayBase display_base );
    virtual void GenerateTransactionTabularText( U64 transaction_id, DisplayBase display_base );

  protected: // functions
  protected: // vars
    TdmAnalyzerSettings* mSettings;
    TdmAnalyzer* mAnalyzer;
};

#endif // TDM_ANALYZER_RESULTS
