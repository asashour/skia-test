DEF_TEST(SkParagraph_ltr, reporter) {
    sk_sp<ResourceFontCollection> fontCollection = sk_make_sp<ResourceFontCollection>();
    if (!fontCollection->fontsFound()) return;
    TestCanvas canvas("SkParagraph_LeftAlignParagraph.png");
    const char* text = "abcd";
    const size_t len = strlen(text);

    ParagraphStyle paragraph_style;
    paragraph_style.setMaxLines(14);
    paragraph_style.setTextAlign(TextAlign::kLeft);
    paragraph_style.turnHintingOff();
    TestParagraphBuilderImpl builder(paragraph_style, fontCollection);

    TextStyle text_style;
    text_style.setFontFamilies({SkString("Roboto")});
    text_style.setFontSize(26);
    text_style.setLetterSpacing(1);
    text_style.setWordSpacing(5);
    text_style.setColor(SK_ColorBLACK);
    text_style.setHeight(1);
    text_style.setDecoration(TextDecoration::kUnderline);
    text_style.setDecorationColor(SK_ColorBLACK);
    builder.pushStyle(text_style);
    builder.addText(text, len);
    builder.pop();

    auto paragraph = builder.Build();
    paragraph->layout(TestCanvasWidth - 100);
    paragraph->paint(canvas.get(), 0, 0);

    auto impl = static_cast<ParagraphImpl*>(paragraph.get());

    RectHeightStyle rect_height_style = RectHeightStyle::kTight;
    RectWidthStyle rect_width_style = RectWidthStyle::kTight;

    // Tests for getRectsForRange()
    auto boxes = paragraph->getRectsForRange(0, 3, rect_height_style, rect_width_style);
    canvas.drawRects(SK_ColorRED, boxes);
    REPORTER_ASSERT(reporter, boxes.size() == 1);

    std::cout << "left: " << boxes[0].rect.left() << std::endl;
    std::cout << "top: " << boxes[0].rect.top() << std::endl;
    std::cout << "right: " << boxes[0].rect.right() << std::endl;
    std::cout << "bottom: " << boxes[0].rect.bottom() << std::endl;

    // Tests for GetGlyphPositionAtCoordinate()
    for (auto x = -100; x < 100; x += 10) {
      std::cout << x << ": " << impl->getGlyphPositionAtCoordinate(x, 0).position << std::endl;
    }
    //REPORTER_ASSERT(reporter, impl->getGlyphPositionAtCoordinate(0, 0).position == 0);
}

DEF_TEST(SkParagraph_rtl, reporter) {
    sk_sp<ResourceFontCollection> fontCollection = sk_make_sp<ResourceFontCollection>();
    if (!fontCollection->fontsFound()) return;
    TestCanvas canvas("SkParagraph_LeftAlignParagraph.png");
    const char* text = "\u05D0\u05D0\u05D0\u05D0";
    const size_t len = strlen(text);

    ParagraphStyle paragraph_style;
    paragraph_style.setMaxLines(14);
    paragraph_style.setTextAlign(TextAlign::kRight);
    paragraph_style.turnHintingOff();
    TestParagraphBuilderImpl builder(paragraph_style, fontCollection);

    TextStyle text_style;
    text_style.setFontFamilies({SkString("Roboto")});
    text_style.setFontSize(26);
    text_style.setLetterSpacing(1);
    text_style.setWordSpacing(5);
    text_style.setColor(SK_ColorBLACK);
    text_style.setHeight(1);
    text_style.setDecoration(TextDecoration::kUnderline);
    text_style.setDecorationColor(SK_ColorBLACK);
    builder.pushStyle(text_style);
    builder.addText(text, len);
    builder.pop();

    auto paragraph = builder.Build();
    paragraph->layout(TestCanvasWidth - 100);
    paragraph->paint(canvas.get(), 0, 0);

    auto impl = static_cast<ParagraphImpl*>(paragraph.get());

    RectHeightStyle rect_height_style = RectHeightStyle::kTight;
    RectWidthStyle rect_width_style = RectWidthStyle::kTight;

    // Tests for getRectsForRange()
    auto boxes = paragraph->getRectsForRange(0, 3, rect_height_style, rect_width_style);
    canvas.drawRects(SK_ColorRED, boxes);
    REPORTER_ASSERT(reporter, boxes.size() == 1);

    std::cout << "left: " << boxes[0].rect.left() << std::endl;
    std::cout << "top: " << boxes[0].rect.top() << std::endl;
    std::cout << "right: " << boxes[0].rect.right() << std::endl;
    std::cout << "bottom: " << boxes[0].rect.bottom() << std::endl;

    // Tests for GetGlyphPositionAtCoordinate()
    for (auto x = -100; x < 100; x += 10) {
      std::cout << x << ": " << impl->getGlyphPositionAtCoordinate(x, 0).position << std::endl;
    }
    // REPORTER_ASSERT(reporter, impl->getGlyphPositionAtCoordinate(0, 0).position == 0);
}
