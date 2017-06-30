(function ($) {
    function customLibOwlThTo(dataRelThIn, indexIn) {
        $('[data-index]', $(dataRelThIn)).removeClass('csas-owl-item-choice');
        $('[data-index="' + indexIn + '"]', $(dataRelThIn)).addClass('csas-owl-item-choice');
        $(dataRelThIn).trigger('to.owl.carousel', [indexIn, 1, true]);
    };
    //Drupal.behaviors.customLibOwl = {
    //    attach: function (context, settings) {
    $(window).load(function () {
        $('.csas-owl-carousel').once('csas-owl', function () {
            var thisOptions = {};
            var thisOptName = ['responsive', 'navText', 'items'];
            var owl = $(this);

            owl.hover(
                function () {
                    $(this).addClass('csas-hover');
                }, function () {
                    $(this).removeClass('csas-hover');
                });

            if (owl.attr('data-options') != 'undefined') {
                thisOptions = JSON.parse($(this).attr('data-options'));
                for (var a in thisOptName) {
                    if (thisOptions[thisOptName[a]] != undefined) {
                        thisOptions[thisOptName[a]] = JSON.parse(thisOptions[thisOptName[a]]);
                    }
                }
            }
            //owl.trigger('play.owl.autoplay',[1000]);
            owl.on('initialized.owl.carousel resized.owl.carousel', function (e) {
                $(this).trigger('csas_owl.refreshed.owl.carousel', [e.type]);
                $(document).trigger('documentChange');
            });

            owl.on('resized.owl.carousel', function (e) {
                $(this).trigger('csas_owl.resized.owl.carousel', [e.type]);
                $(document).trigger('documentChange');
            });

            owl.owlCarousel(thisOptions);

            function csasOwlApl(owlIn) {

                if (!owlIn.hasClass('csas-hover')) {
                    owlIn.trigger('next.owl');
                }
            }

            if (owl.hasClass('csas-owl-apl')) { //fix animation + auto play
                setInterval(csasOwlApl, thisOptions.autoplayTimeout, owl);
            }

            if ($('.owl-dots:not(.disabled)', owl).length) {
                owl.addClass('csas-owl-wi-dots');
            }
            owl.on('mousewheel', '.owl-stage', function (e) {
                var owlHasPages = 1;
                if ($('.owl-prev.disabled', owl).length && $('.owl-next.disabled', owl).length) {
                    owlHasPages = 0;
                }
                if (owlHasPages) {
                    if (e.deltaY > 0) {
                        owl.trigger('next.owl');
                    } else {
                        owl.trigger('prev.owl');
                    }
                    //e.preventDefault();
                    return false;
                }
            });
            if (owl.hasClass('csas-owl-gal-th')) {
                var dataRelPr = owl.attr('data-rel-pr');
                var dataIndex = 0;
                $('[data-index]', owl).on('click', function () {
                    dataIndex = $(this).attr('data-index');
                    $('[data-index]', owl).removeClass('csas-owl-item-choice');
                    $(this).addClass('csas-owl-item-choice');
                    $(dataRelPr).trigger('to.owl.carousel', [dataIndex, 1, true]);
                });
            }
            if (owl.hasClass('csas-owl-gal-pr')) {
                var dataRelTh = owl.attr('data-rel-th');
                var dataIndex = 0;
                owl.on('changed.owl.carousel', function (e) {
                    customLibOwlThTo(dataRelTh, e.item.index);
                });

                $(document).bind('cbox_complete', function () {
                    var dataRelPrItem = '';
                    var dataIndexItem = -1;
                    var cboxEl = $.colorbox.element();

                    if (cboxEl.attr('data-rel-pr') != undefined) {
                        dataRelPrItem = cboxEl.attr('data-rel-pr');
                    }

                    if (cboxEl.attr('data-index') != undefined) {
                        dataIndexItem = cboxEl.attr('data-index');
                    }

                    if (dataRelPrItem != '' && dataIndexItem > -1) {
                        var dataRelThItem = '';
                        if ($(dataRelPrItem).attr('data-rel-th') != undefined) {
                            dataRelThItem = $(dataRelPrItem).attr('data-rel-th');
                            customLibOwlThTo(dataRelThItem, dataIndexItem);
                        }
                        $(dataRelPrItem).trigger('to.owl.carousel', [dataIndexItem, 1, true]);
                    }
                });
            }
        });
    });
    //    }
    //};

})(jQuery);