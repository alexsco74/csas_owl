<?php
/**
 * @file
 * Page callbacks for csas_owl.
 */
function csas_owl_pages_example() {
  $build['wr'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('csas-owl-example')
    ),
    '#attached' => array(
      'css' => array(drupal_get_path('module', 'csas_owl') . '/css/csas_owl_demo.css')
    )
  );

  //'trade-pf-catalog-parent-terms-df-view',
  $build['wr']['node'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => 'Csas owl example.'
  );

  $content = '<img class="owl-lazy" data-src="https://placehold.it/350x250&text=1" data-src-retina="https://placehold.it/350x250&text=1-retina" alt="">
    <img class="owl-lazy" data-src="https://placehold.it/350x250&text=2" data-src-retina="https://placehold.it/350x250&text=2-retina" alt="">
    <img class="owl-lazy" data-src="https://placehold.it/350x250&text=3" alt="">
    <img class="owl-lazy" data-src="https://placehold.it/350x250&text=4" alt="">
    <img class="owl-lazy" data-src="https://placehold.it/350x250&text=5" alt="">
    <img class="owl-lazy" data-src="https://placehold.it/350x250&text=6" alt="">
    <img class="owl-lazy" data-src="https://placehold.it/350x250&text=7" alt="">
    <img class="owl-lazy" data-src="https://placehold.it/350x250&text=8" alt="">
    <img class="owl-lazy" data-src="https://placehold.it/350x250&text=9" alt="">
    <img class="owl-lazy" data-src="https://placehold.it/350x250&text=10" alt="">
    <img class="owl-lazy" data-src="https://placehold.it/350x250&text=11" alt="">';

//variant #1
//   'items' => 5,
//   'autoWidth' => TRUE,

//variant #2
//  $responsive = '{"0":{"items":"2"},"320":{"items":"4"},"640":{"items":"6"},"1280":{"items":"7"},"1600":{"items":"8"}}';
//  'responsive' => $responsive,
//see https://github.com/smashingboxes/OwlCarousel2

  //$responsive = '{"0":{"items":"1"},"320":{"items":"2"},"640":{"items":"4"},"1280":{"items":"7"},"1600":{"items":"8"}}';
  $responsive = '{"0":{"items":"9"}}';
  $attr_data = array(
    'lazyLoad' => TRUE,
    'margin' => 10,
    'items' => 5,
    'nav' => TRUE,
    'navContainerClass' => 'csas-owl-nav',
    'navText' => '["<span>prev</span>", "<span>next</span>"]',
    'animateOut' => 'fadeOut'
  );
  $build['wr']['lazy'] = array(
    '#prefix' => '<label>Lazy load</label>',
    '#type' => 'container',

    '#attached' => array(
      'library' => array(array('csas_owl', 'csas_owl_carousel'))
    ),
    '#attributes' => array(
      'class' => array(
        'owl-carousel',
        'csas-owl-carousel',
        'owl-theme'
      ),
      'data-options' => drupal_json_encode($attr_data)
    ),
    'content' => array('#markup' => $content),
  );

  //base
  $responsive = '{"0":{"items":"5"}}';
  $content = '<div class="csas-owl-item"><h4>1</h4></div>
    <div class="csas-owl-item"><h4>2</h4></div>
    <div class="csas-owl-item"><h4>3</h4></div>
    <div class="csas-owl-item"><h4>4</h4></div>
    <div class="csas-owl-item"><h4>5</h4></div>
    <div class="csas-owl-item"><h4>6</h4></div>
    <div class="csas-owl-item"><h4>7</h4></div>
    <div class="csas-owl-item"><h4>8</h4></div>
    <div class="csas-owl-item"><h4>9</h4></div>
    <div class="csas-owl-item"><h4>10</h4></div>
    <div class="csas-owl-item"><h4>11</h4></div>
    <div class="csas-owl-item"><h4>12</h4></div>';

  //   'responsive' => $responsive,

  $attr_data = array(
    'responsive' => $responsive,
    'margin' => 10,
    'nav' => TRUE,
    'navContainerClass' => 'csas-owl-nav',
    'navText' => '["<span>prev</span>", "<span>next</span>"]',
    'animateOut' => 'fadeOut',
  );
  $build['wr']['base'] = array(
    '#prefix' => '<label>Base with custom nav</label>',
    '#type' => 'container',
    '#attached' => array(
      'library' => array(array('csas_owl', 'csas_owl_carousel'))
    ),
    '#attributes' => array(
      'class' => array(
        'owl-carousel',
        'csas-owl-carousel',
        'owl-theme',
        'owl-demo',
        'csas-owl-demo-con'
      ),
      'data-options' => drupal_json_encode($attr_data)
    ),
    'content' => array('#markup' => $content),
  );

  //animate
  $content = '<div class="item">
              <h4>1</h4>
            </div>
            <div class="item">
              <h4>2</h4>
            </div>
            <div class="item">
              <h4>3</h4>
            </div>
            <div class="item">
              <h4>4</h4>
            </div>
            <div class="item">
              <h4>5</h4>
            </div>
            <div class="item">
              <h4>6</h4>
            </div>
            <div class="item">
              <h4>7</h4>
            </div>
            <div class="item">
              <h4>8</h4>
            </div>
            <div class="item">
              <h4>9</h4>
            </div>
            <div class="item">
              <h4>10</h4>
            </div>
            <div class="item">
              <h4>11</h4>
            </div>
            <div class="item">
              <h4>12</h4>
            </div>';
  drupal_add_css(drupal_get_path('module', 'csas_owl') . '/css/animate.min.css');
  $attr_data = array(
    'animateOut' => 'zoomOut',
    'animateIn' => 'zoomIn',
    'items' => 1,
    'dotsEach' => TRUE,
    'margin' => 0,
    'center' => TRUE,
    'nav' => TRUE,
    'loop' => TRUE,
    'navContainerClass' => 'csas-owl-nav',
    'navText' => '["<span>prev</span>", "<span>next</span>"]',
  );
  $build['wr']['ani'] = array(
    '#prefix' => '<label>Animate</label>',
    '#type' => 'container',
    '#attached' => array(
      'library' => array(array('csas_owl', 'csas_owl_carousel'))
    ),
    '#attributes' => array(
      'class' => array(
        'owl-carousel',
        'csas-owl-carousel',
        'owl-theme',
        'owl-demo',
        'csas-owl-demo-con'
      ),
      'data-options' => drupal_json_encode($attr_data)
    ),
    'content' => array('#markup' => $content),
  );

  //animate slide show
  $content = '<div class="item">
              <h4>1</h4>
            </div>
            <div class="item">
              <h4>2</h4>
            </div>
            <div class="item">
              <h4>3</h4>
            </div>
            <div class="item">
              <h4>4</h4>
            </div>
            ';
  drupal_add_css(drupal_get_path('module', 'csas_owl') . '/css/animate.min.css');
  $attr_data = array(
    'animateOut' => 'zoomOut',
    'animateIn' => 'zoomIn',
    'autoplay' => TRUE,
    'autoplayTimeout' => 3000,
    'autoplayHoverPause' => TRUE,
    'items' => 1,
    'dotsEach' => TRUE,
    'margin' => 0,
    'center' => TRUE,
    'nav' => TRUE,
    'loop' => TRUE,
    'navContainerClass' => 'csas-owl-nav',
    'navText' => '["<span>prev</span>", "<span>next</span>"]',
  );
  $build['wr']['ani_sld_shw'] = array(
    '#prefix' => '<label>Animate slide show</label>',
    '#type' => 'container',
    '#attached' => array(
      'library' => array(array('csas_owl', 'csas_owl_carousel'))
    ),
    '#attributes' => array(
      'class' => array(
        'owl-carousel',
        'csas-owl-carousel',
        'owl-theme',
        'owl-demo',
        'csas-owl-demo-con'
      ),
      'data-options' => drupal_json_encode($attr_data)
    ),
    'content' => array('#markup' => $content),
  );

  return $build;
}